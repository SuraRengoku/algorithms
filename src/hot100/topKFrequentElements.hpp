#include "../leetcodeheader.h"

class topKFE {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

    vector<int> solution1(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> count;
        for(auto num : nums)
            count[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for(auto& [num, c] : count) {
            if(q.size() == k) {
                if(q.top().second < c) {
                    q.pop();
                    q.emplace(num, c);
                }
            } else {
                q.emplace(num, c);
            }
        }

        while(!q.empty()) {
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }

    vector<int> solution2(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> count;
        int maxOc = 0;
        for(int num : nums){
            count[num]++;
            maxOc =  max(maxOc, count[num]);
        }

        vector<vector<int>> buckets(maxOc + 1);
        for(auto& [num, c] : count)
            buckets[c].push_back(num);

        for(int i = maxOc; i >= 0; --i){
            if(ans.size() == k)
                break;
             ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
        }
        return ans;
    }
};;