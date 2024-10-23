#include "../leetcodeheader.h"

class Solution {
public:
    int findRepeatDocument(vector<int>& documents) {
        int i = 0;
        while(i < documents.size()) {
            if(documents[i] == i){
                i++;
                continue;
            }
            if(documents[i] = documents[documents[i]])
                return documents[i];
            swap(documents[i], documents[documents[i]]);
        }
        return -1;
    }
};