#include "../leetcodeheader.h"

class MedianFinder {
private:
    priority_queue<int, vector<int>, std::greater<int>> A;
    priority_queue<int, vector<int>, std::less<int>> B;
public:
    MedianFinder() {}

    void addNum(int num) {
        if(A.size() != B.size()) {
            A.push(num);
            B.push(A.top());
            A.pop();
        } else {
            B.push(num);
            A.push(B.top());
            B.pop();
        }
    }

    double findMedian() {
        return A.size() != B.size() ? A.top() : (A.top() + B.top()) / 2.0f;
    }
};  