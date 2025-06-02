#include "../leetcodeheader.h"

class bestStocks {
public:
    int solution1(vector<int>& prices) {
        int maxPf = 0, minPc = prices[0];
        int len = prices.size();
        for(int i = 0; i < len; ++i) {
            maxPf = max(maxPf, prices[i] - minPc);
            minPc = min(minPc, prices[i]);
        }
        return maxPf;
    }

    int solution2(vector<int>& prices) {
        int maxPf = 0;
        
        return maxPf; 
    }
};