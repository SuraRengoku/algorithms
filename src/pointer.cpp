#include<iostream>
using namespace std;

int pointertest(int* a){
    cout<<a<<endl;
    cout<<*a<<endl;
    return *a;
}

int referencetest(int& a){
    cout<<a<<endl;
    cout<<&a<<endl;
    return a;
}
int main(){
    int a=3;
    int& e=a;
    int* b=&a;
    int* c;
    int* d=nullptr;
    cout<<&a<<endl;
    cout<<b<<endl;
    cout<<*b<<endl;
    pointertest(b);
    referencetest(a);
    // cout<<c<<endl;
    // cout<<*c<<endl;
    // cout<<d<<endl;
    // cout<<*d<<endl;
    return 1;
}