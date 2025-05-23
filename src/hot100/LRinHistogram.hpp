#include "..\leetcodeheader.h"

class Solution1 {
public:
    int largestRectangleArea(vector<int> &heights) {
        int len = heights.size();
        int ans = 0;
        vector<int> lmono(len, -1);
        stack<int> stk;
        for(int i = 0; i < len; ++i) {
            while(!stk.empty() && heights[i] <= heights[stk.top()])
                stk.pop();
            if(!stk.empty())
                lmono[i] = stk.top();
            stk.push(i);
        }
        vector<int> rmono(len, len);
        stk = stack<int>();
        for(int i = len - 1; i >= 0; --i) {
            while(!stk.empty() && heights[i] <= heights[stk.top()])
                stk.pop();
            if(!stk.empty())
                rmono[i] = stk.top();
            stk.push(i);
        }

        for(int i = 0; i < len; ++i) {
            ans = max(anx, heights[i] * (rmono[i] - lmono[i] - 1));
        }
        return ans;
    }
}

