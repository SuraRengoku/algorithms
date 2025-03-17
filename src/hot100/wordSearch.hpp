#include "../leetcodeheader.h"

class Solution {
private:
    static constexpr int offsets[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    bool exist(vector<vector<char>> &board, string word) {
        unordered_map<char, int> count;
        unordered_map<char, int> wordCount;

        for(auto &line : board) {
            for(auto &ele : line) {
                count[ele]++;
            }
        }
        
        for(auto & c : word){
            if(++wordCount[c] > word[c])
                return false;
        }

        int len = word.size();
        int m = board.size(), n = board[0].size();
        vector<vector<int>> mark(m, vector<int>(n, 0));

        if(count[word.back()] < count[word.front()])
            reverse(word.begin(), word.end());

        auto dfs = [&](auto &&dfs, int i, int j, int k) -> bool {
            if(board[i][j] != word[k])
                return false;
            if(len == k + 1) // implicit that board[i][j] == word[k]
                return true;
            mark[i][j] = 1;
            for(auto &offset : offsets) {
                int x = i + offset[0], y = j + offset[1];
                if(x >= 0 && x < m && y >=0 && y < n && mark[x][y] == 0 && dfs(dfs, x, y, k + 1))
                    return true;
            }
            mark[i][j] = 0;
            return false;
        };
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(dfs(dfs, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};