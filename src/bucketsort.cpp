#include "generator.cpp"
//桶排序的速度很大程度上取决于每个桶内采用的排序算法，这里使用快速排序

//荷兰国旗分组
auto partition(int *a, int l, int r, int end)->int*{
    int indle=l-1;//小于界左
    int indla=r;//大于界右
    int ind=l;//遍历指数
    while(ind<indla){
        if(a[ind]<end)
            bswap_nonzero(a,ind++,++indle);
        else if(a[ind]==end)
            ind++;
        else if(a[ind]>end)
            bswap_nonzero(a,ind,--indla);
    }
    bswap_nonzero(a,r,indla);
    int* result=new int[2];//存储 等于区域 的左界和右界,全包含
    result[0]=indle+1;
    result[1]=indla;
    return result;
}

/**
 * @param a the array pointer
 * @param l the left index
 * @param r the right index 
*/
void fastsort(int *a, int l, int r){
    if(l<r){
        //当l==r时表示左右分类完毕
        pair<int, int> range(l, r);
        bswap(a, RandNumGene(range), r);//将要排序的部分中随机一个量换到尾部去
        int end=a[r];
        int *result=partition(a, l, r, end);
        fastsort(a,l,result[0]-1);
        fastsort(a,result[1]+1,r);
    }
}

void bucketsort(int *a, int length, int range, int radix){
    try{
        if(!radix)
            throw runtime_error("radix cannot be zero");
    }catch(runtime_error err){
        cerr<<err.what()<<"\n";
    }
    const int num=range/radix+(range%radix?1:0);
    vector<vector<int>> buckets;
    for(int k=0;k<num;k++){
        vector<int> bucket;
        buckets.push_back(bucket);
    }
    // cout<<"number of buckets: "<<buckets.size();
    for(int i=0;i<length;i++){
        int bucketnum=a[i]/radix;
        buckets.at(bucketnum).push_back(a[i]);
    }
    // for(int j=0;j<buckets.size();j++){
    //     for(int m=0;m<buckets.at(j).size();m++)
    //         cout<<buckets.at(j).at(m)<<" ";
    //     cout<<"\n";
    // }
    int ind=0;
    for(int j=0;j<buckets.size();j++){
        int *arr=new int[buckets[j].size()];
        // cout<<buckets[j].size()<<"\n";
        for(int n=0;n<buckets[j].size();n++)
            arr[n]=buckets[j][n];
        // bprint(arr,buckets[j].size());
        fastsort(arr,0,buckets[j].size()-1);
        int tempind=0;
        while(tempind<buckets[j].size())
            a[ind++]=arr[tempind++];
    }
    // int ind=0;
    // while(ind<length){
    //     for(int k=0;k<num;k++){
    //         if(buckets[k].empty())
    //             continue;
    //         else{
    //             for(int m=0;m<buckets[k].size();m++)
    //                 a[ind++]=buckets[k].at(m);
    //         }
    //     }
    // }
}

int main(){
    int Maxsize=300;
    int Maxvalue=300;
    pair<int*,int> result=generator(Maxsize,Maxvalue,1);
    int *arr=result.first;
    int len=result.second;
    int test[]={4,1,3,7,3,2,6,9,5,1};
    bprint(arr, len);
    // bprint(test,10);
    bucketsort(arr, len, Maxvalue, 20);
    // bucketsort(test, 10, 10, 2);
    // fastsort(arr, 0, len-1);
    bprint(arr, len);
    // bprint(test,10);
    return 0;
}