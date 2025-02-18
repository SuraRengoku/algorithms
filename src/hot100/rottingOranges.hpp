#include "../leetcodeheader.h"

class solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        vector<vector<int>> offset{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        vector<pair<int, int>> rotten;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 2)
                    rotten.emplace_back(i, j);
                if(grid[i][j] == 1)
                    ++fresh;
            }
        }

        int ans = 0;
        while(!rotten.empty() && fresh) {
            ++ans;
            vector<pair<int, int>> nxt;
            for(auto &[x, y] : rotten) {
                for(auto os : offset) {
                    int row = x + os[0], col = y + os[1];
                    if(row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1){
                        --fresh;
                        grid[row][col] = 2;
                        nxt.emplace_back(row, col);
                    }
                }
            }
            rotten = move(nxt);
        }
        return fresh == 0 ? ans : -1;
    }
};