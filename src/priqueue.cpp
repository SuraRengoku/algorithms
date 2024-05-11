#include<iostream>
#include<queue>

int main() {
    // 创建小根堆，使用 vector 作为底层容器
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // 向小根堆中插入元素
    minHeap.push(5);
    minHeap.push(4);
    minHeap.push(7);
    minHeap.push(3);
    minHeap.push(8);
    minHeap.push(1);
    minHeap.push(10);

    // 输出小根堆中的元素
    std::cout << "Min Heap elements: ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " "; // 输出堆顶元素
        minHeap.pop(); // 弹出堆顶元素
    }
    std::cout << std::endl;

    return 0;
}