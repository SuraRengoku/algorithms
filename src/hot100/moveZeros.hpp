#include "../leetcodeheader.h"

class moveZeros {
public:
    void moveZ(vector<int>& nums) {
        int i0 = 0;
        for(auto& num : nums) {
            if(num)
                swap(num, nums[i0++]);
        }
    }
};