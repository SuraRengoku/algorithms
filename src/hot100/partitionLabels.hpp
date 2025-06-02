#include "../leetcodeheader.h"

class partitionLabels {
public:
    vector<int> labels(string s) {
        vector<int> ans;
        int curFarthest = 0;
        int lastCut = 0;
        int len = s.size();
        unordered_map<int, int> lidx;
        for(int i = 0; i < len; ++i)
            lidx[s[i]] = i;

        for(int i = 0; i < len; ++i) {
            curFarthest = max(curFarthest, lidx[s[i]]);
            if(i == curFarthest) {
                ans.push_back(curFarthest + 1 - lastCut);
                lastCut = curFarthest + 1;
            }
        }

        return ans;
    }
};