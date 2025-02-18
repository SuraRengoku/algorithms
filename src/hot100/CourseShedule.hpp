#include "../leetcodeheader.h"

class solution1 {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> indegrees(numCourses);
        vector<vector<int>> adjacency(numCourses, vector<int>{});
        queue<int> sorted{};
        for(auto &pre : prerequisites) {
            indegrees[pre[0]]++;
            adjacency[pre[1]].emplace_back(pre[0]);
        }
        for(int i = 0; i < numCourses; ++i) {
            if(indegrees[i] == 0)
                sorted.push(i);
        }
        while(!sorted.empty()) {
            int cur = sorted.front();
            sorted.pop();
            --numCourses;   
            for(int cut : adjacency[cur]){
                if(--indegrees[cut] == 0)
                    sorted.push(cut);
            }
        }
        return numCourses == 0;
    }
};

class solution2 {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adjacency(numCourses, vector<int>{});
        vector<int> flags(numCourses, 0);
        for(auto &pre : prerequisites){
            adjacency[pre[1]].push_back(pre[0]);
        }

        auto dfs = [&](auto&& dfs, int cur) -> bool {
            if(flags[cur] == -1)
                return true;
            if(flags[cur] == 1) 
                return false;
            flags[cur] = 1;
            for(int adj : adjacency[cur]) {
                if(!dfs(dfs, adj))
                    return false;
            }
            flags[cur] = -1;
            return true;
        };

        for(int i = 0; i < numCourses; ++i) {
            if(!dfs(dfs, i))
                return false;
        }
        return true;
    }
};