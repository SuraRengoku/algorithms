#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<__cplusplus<<endl;
    vector<int> arr = {1, 2 ,3};
    for(auto& num : arr) {
        cout << num << endl;
    }
    return 0;
}
