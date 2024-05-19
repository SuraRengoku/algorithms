#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
    /**
    * @return true if for all keys in a, their value is greater or equal to value in b
    */
    bool CompMap(unordered_map<char, int>& a,unordered_map<char, int>& b){
        for(auto pair:b){
            if(a[pair.first]<pair.second)
                return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        int m=s.size(), left=0;
        unordered_map<char,int> need,window;
        int sublen=INT_MAX, Ileft=-1, Iright=m;
        for(auto c:t) need[c]+=1;
        for(int right=0; right<m; ++right){
            window[s[right]]++;
            while(CompMap(window,need)){ //当window不再满足条件时跳出
                if(right-left<Iright-Ileft){
                    Iright=right;
                    Ileft=left;
                }
                window[s[left++]]--;
            }
        }
        return Ileft==-1?"":s.substr(Ileft,Iright-Ileft+1);
    }
};

int main() {
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << sol.minWindow(s, t) << endl;
    return 0;
}