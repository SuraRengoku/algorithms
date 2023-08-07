#include <fcntl.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <OpenCL/opencl.h>
 
 
 
// Use a static data size for simplicity
//
#define DATA_SIZE (1024)
 
 
 
// Simple compute kernel which computes the square of an input array 
// 这是OPENCL用于计算的内核部分源码，跟C相同的语法格式，通过编译后将发布到GPU设备
//（或者将来专用的计算设备）上面去执行。因为显卡通常有几十、上百个内核，所以这部分
// 需要设计成可并发的程序逻辑。
// 
const char *KernelSource = "\n" \
"__kernel void square(                                                       \n" \
"   __global float* input,                                              \n" \
"   __global float* output,                                             \n" \
"   const unsigned int count)                                           \n" \
"{                                                                      \n" \
// 并发逻辑主要是在下面这一行体现的，i的初始值获取当前内核的id（整数）,根据id计算自己的那一小块任务
"   int i = get_global_id(0);                                           \n" \
"   if(i < count)                                                       \n" \
"       output[i] = input[i] * input[i];                                \n" \
"}                                                                      \n" \
"\n";
 
 
 
int main(int argc, char** argv)
{
    int err;                            // error code returned from api calls
      
    float data[DATA_SIZE];              // original data set given to device
    float results[DATA_SIZE];           // results returned from device
    unsigned int correct;               // number of correct results returned
 
    size_t global;                      // global domain size for our calculation
    size_t local;                       // local domain size for our calculation
 
    cl_device_id device_id;             // compute device id 
    cl_context context;                 // compute context
    cl_command_queue commands;          // compute command queue
    cl_program program;                 // compute program
    cl_kernel kernel;                   // compute kernel
    
    cl_mem input;                       // device memory used for the input array
    cl_mem output;                      // device memory used for the output array
    
    // Fill our data set with random float values
    //
    int i = 0;
    unsigned int count = DATA_SIZE;
    //随机产生一组浮点数据，用于给GPU进行计算
    for(i = 0; i < count; i++)
        data[i] = rand() / (float)RAND_MAX;
    
    // Connect to a compute device
    //
    int gpu = 1;
    // 获取GPU设备，OPENCL的优势是可以使用CPU进行模拟，当然这种功能只是为了在没有GPU设备上进行调试
    // 如果上面变量gpu=0的话，则使用CPU模拟
    err = clGetDeviceIDs(NULL, gpu ? CL_DEVICE_TYPE_GPU : CL_DEVICE_TYPE_CPU, 1, &device_id, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to create a device group!\n");
        return EXIT_FAILURE;
    }
  
    // Create a compute context 
    // 建立一个GPU计算的上下文环境，一组上下文环境保存一组相关的状态、内存等资源
    context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
    if (!context)
    {
        printf("Error: Failed to create a compute context!\n");
        return EXIT_FAILURE;
    }
 
    // Create a command commands
    //使用获取到的GPU设备和上下文环境监理一个命令队列，其实就是给GPU的任务队列
    commands = clCreateCommandQueue(context, device_id, 0, &err);
    if (!commands)
    {
        printf("Error: Failed to create a command commands!\n");
        return EXIT_FAILURE;
    }
 
    // Create the compute program from the source buffer
    //将内核程序的字符串加载到上下文环境
    program = clCreateProgramWithSource(context, 1, (const char **) & KernelSource, NULL, &err);
    if (!program)
    {
        printf("Error: Failed to create compute program!\n");
        return EXIT_FAILURE;
    }
 
    // Build the program executable
    //根据所使用的设备，将程序编译成目标机器语言代码，跟通常的编译类似，
    //内核程序的语法类错误信息都会在这里出现，所以一般尽可能打印完整从而帮助判断。
    err = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        size_t len;
        char buffer[2048];
 
        printf("Error: Failed to build program executable!\n");
        clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, sizeof(buffer), buffer, &len);
        printf("%s\n", buffer);
        exit(1);
    }
 
    // Create the compute kernel in the program we wish to run
    //使用内核程序的函数名建立一个计算内核
    kernel = clCreateKernel(program, "square", &err);
    if (!kernel || err != CL_SUCCESS)
    {
        printf("Error: Failed to create compute kernel!\n");
        exit(1);
    }
 
    // Create the input and output arrays in device memory for our calculation
    // 建立GPU的输入缓冲区，注意READ_ONLY是对GPU而言的，这个缓冲区是建立在显卡显存中的
    input = clCreateBuffer(context,  CL_MEM_READ_ONLY,  sizeof(float) * count, NULL, NULL);
    // 建立GPU的输出缓冲区，用于输出计算结果
    output = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(float) * count, NULL, NULL);
    if (!input || !output)
    {
        printf("Error: Failed to allocate device memory!\n");
        exit(1);
    }    
    
    // Write our data set into the input array in device memory 
    // 将CPU内存中的数据，写入到GPU显卡内存（内核函数的input部分）
    err = clEnqueueWriteBuffer(commands, input, CL_TRUE, 0, sizeof(float) * count, data, 0, NULL, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to write to source array!\n");
        exit(1);
    }
 
    // Set the arguments to our compute kernel
    // 设定内核函数中的三个参数
    err = 0;
    err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &input);
    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &output);
    err |= clSetKernelArg(kernel, 2, sizeof(unsigned int), &count);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to set kernel arguments! %d\n", err);
        exit(1);
    }
 
    // Get the maximum work group size for executing the kernel on the device
    //获取GPU可用的计算核心数量
    err = clGetKernelWorkGroupInfo(kernel, device_id, CL_KERNEL_WORK_GROUP_SIZE, sizeof(local), &local, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to retrieve kernel work group info! %d\n", err);
        exit(1);
    }
 
    // Execute the kernel over the entire range of our 1d input data set
    // using the maximum number of work group items for this device
    // 这是真正的计算部分，计算启动的时候采用队列的方式，因为一般计算任务的数量都会远远大于可用的内核数量，
    // 在下面函数中，local是可用的内核数，global是要计算的数量，OPENCL会自动执行队列，完成所有的计算
    // 所以在前面强调了，内核程序的设计要考虑、并尽力利用这种并发特征
    global = count;
    err = clEnqueueNDRangeKernel(commands, kernel, 1, NULL, &global, &local, 0, NULL, NULL);
    if (err)
    {
        printf("Error: Failed to execute kernel!\n");
        return EXIT_FAILURE;
    }
 
    // Wait for the command commands to get serviced before reading back results
    // 阻塞直到OPENCL完成所有的计算任务
    clFinish(commands);
 
    // Read back the results from the device to verify the output
    // 从GPU显存中把计算的结果复制到CPU内存
    err = clEnqueueReadBuffer( commands, output, CL_TRUE, 0, sizeof(float) * count, results, 0, NULL, NULL );  
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to read output array! %d\n", err);
        exit(1);
    }
    
    // Validate our results
    // 下面是使用CPU计算来验证OPENCL计算结果是否正确
    correct = 0;
    for(i = 0; i < count; i++)
    {
        if(results[i] == data[i] * data[i])
            correct++;
    }
    
    // Print a brief summary detailing the results
    // 显示验证的结果
    printf("Computed '%d/%d' correct values!\n", correct, count);
    
    // Shutdown and cleanup
    // 清理各类对象及关闭OPENCL环境
    clReleaseMemObject(input);
    clReleaseMemObject(output);
    clReleaseProgram(program);
    clReleaseKernel(kernel);
    clReleaseCommandQueue(commands);
    clReleaseContext(context);
    
    printf("Done.\n");
    return 0;
}