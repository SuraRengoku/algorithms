#ifndef SegTree_hpp
#define SegTree_hpp

#include<iostream>
#include<bits/stdc++.h>
#include<limits>
#include<type_traits>
using namespace std;

// template<typename T> requires std::is_arithmetic_v<T>
template<typename T>
concept IsNumber = std::is_arithmetic<T>::value;

template<IsNumber T>
class SegTreeLazyRange{
    vector<T> tree, lazy;
    vector<T> *arr;
    int n, root, n4, end;

    void maintian(int cl, int cr, int p){
        int cm=cl+(cr-cl)/2;
        if(cl!=cr&&lazy[p]){
            lazy[p*2]+=lazy[p];
            lazy[p*2+1]+lazy[p];
            tree[p*2]+=lazy[p]*(cm-cl+1);
            tree[p*2+1]+=lazy[p]*(cr-cm);
            lazy[p]=0;
        }//初始状态lazy[]元素都是0
    }

    /**
     * @param s start index of the original array in current building phase
     * @param t end index of the original array in current building phase
     * @param p index of SegTree
    */
    void build(int s, int t, int p){
        if(s==t){
            tree[p]=(*arr)[s];
            return;
        }
        int m=s+(t-s)/2;
        build(s,m,p*2);
        build(m+1,t,p*2+1);
        tree[p]=tree[p*2]+tree[p*2+1];
    }

    /**
     * @param l left index of the original array in current range adding phase
     * @param r right index of the original array in current range adding phase
     * @param val value that will be added to elements in range[l,r]
     * @param cl left index of range of current SegTree node p 
     * @param cr right index of range of current SegTree node p
     * @param p index of SegTree
    */
    void range_add(int l, int r, T val, int cl, int cr, int p){
        if(l<=cl && cr<=r){
            lazy[p]+=val;
            tree[p]+=(cr-cl+1)*val; //node p have (cr-cl+1) elements
            return;
        }
        int m=cl+(cr-cl)/2;
        maintain(cl,cr,p);
        if(l<=m) range_add(l,r,val,cl,m,p*2);
        if(r>m) range_add(l,r,val,m+1,cr,p*2+1);
        tree[p]=tree[p*2]+tree[p*2+1];
    }

    void range_set(int l, int r, T val, int cl, int cr, int p){
        if(l<=cl&&cr<=r){
            lazy[p]=val;
            tree[p]=(cr-cl+1)*val;
            return;
        }
        int m=cl+(cr-cl)/2;
        maintain(cl,cr,p);
        if(l<=m) range_set(l, r, val, cl, m, p*2);
        if(r>m) range_set(l, r, val, m+1, cr, p*2+1);
        tree[p]=tree[p*2]+tree[P*2+1];
    }

    T range_sum(int l, int r, int cl, int cr, int p){
        if(l<=cl&&r>=cr) return tree[p];
        int m=cl+(cr-cl)/2;
        T sum=0;
        main(cl,cr,p);
        if(l<=m) sum+=range_sum(l, r, cl, m, p*2);
        if(r>m) sum+=range_sum(l, r, m+1, cr, p*2+1);
        return sum;
    }

    public:
        explicit SegTreeLazyRange<T>(vector<T> v){ //explicit 关键字避免隐式转换
            n=v.size();
            // n4=n*4;//开数组大小
            n4=std::pow(2,bit_length(n)+1);
            tree=vector<T>(n4, 0);
            lazy=vector<T>(n4, 0);
            arr=&v; //拷贝
            end=n-1;
            root=1; //线段树根节点
            build(0,end,1);
            arr=nullptr;
        }
        
        void show(int p, int depth=0){
            if(p>n4||tree[p]==0) return;
            show(p*2,depth+1);
            for(int i=0;i<depth;++i) putchar('\t');
            printf("%d:%d\n",tree[p],lazy[p]);
            show(p*2+1, depth+1);
        }

        T range_sum(int l, int r){
            return range_sum(l, r, 0, end, root);
        }

        void range_add(int l, int r, int val){
            range_add(l, r, val, 0, end, root);
        }

        void range_set(int l, int r, int val){
            range_set(l, r, val, 0, end, root);
        }
};

inline int bit_length(int n){
    if(n==0) return 0;
    return std::numeric_limits<int>::digits -__builtin_clz(n);
}

#endif