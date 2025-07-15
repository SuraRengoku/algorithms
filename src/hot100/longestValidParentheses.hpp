#include "../leetcodeheader.h"

class LVP {
public:
    int solution (string s) {
        int len = s.size();
        vector<int> cache(len, 0);
        int ans = 0;

        for(int i = 1; i < len; ++i) {
            if(s[i] == ')') {
                if(s[i - 1] == '(') {
                    cache[i] = 2;
                    if(i - 2 >= 0)
                        cache[i] += cache[i - 2];
                } else {
                    if(i - cache[i - 1] - 1 >= 0 && s[i - cache[i - 1] - 1] == '(') {
                        cache[i] = cache[i - 1] + 2; 
                        if(i - cache[i - 1] - 2 >= 0)
                            cache[i] += cache[i - cache[i - 1] - 2];
                    }
                }
            }
            ans = max(ans, cache[i]);
        }
        return ans;
    }
};