#include "../leetcodeheader.h"

class ProductArray {
public:
    vector<int> productExceptSelf1(vector<int>& nums) {
        int len = nums.size();
        vector<int> prePro(len, 1), sufPro(len, 1);

        for(int i = 1; i < len; ++i)
            prePro[i] = nums[i - 1] * prePro[i - 1];
        for(int i = len - 2; i >= 0; --i)
            sufPro[i] = nums[i + 1] * sufPro[i + 1];
        
        vector<int> ans(len, 1);
        for(int i = 0; i < len; ++i) 
            ans[i] = prePro[i] * sufPro[i];
        return ans;
    }

    vector<int> productExceptSelf2(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len, 1), sufPro(len, 1);

        for(int i = len - 2; i >= 0; --i)
            sufPro[i] = nums[i + 1] * sufPro[i + 1];

        int pre = 1; 
        for(int i = 0; i < len; ++i) {
            ans[i] = pre * sufPro[i];
            pre *= nums[i];
        }
        return ans;
    }
};