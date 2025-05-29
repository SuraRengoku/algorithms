#include "../leetcodeheader.h"

class solution1 {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int> count;
        count.reserve((len - 1) / 2 + 1);
        for(int num : nums)
            count[num]++;
        for(auto c : count) {
            if(c.second == 1)
                return c.first;
        }
        return 0;
    }
};

class solution2 {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for(int num : nums)
            a ^= num;
        return a;
    }
};