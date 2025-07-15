#include "src/hot100/bestStocks.hpp"
#include "src/hot100/houseRobber.hpp"
#include "src/hot100/perfectSquares.hpp"
#include "src/hot100/minSizeSubarraySum.hpp"

int main(int, char**){
    minSizeSubarraySum msss;
    vector<int> nums{2,3,1,2,4,3};
    return msss.minSubarrayLen(7,  nums);
}
