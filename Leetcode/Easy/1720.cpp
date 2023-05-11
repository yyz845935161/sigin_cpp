#include <vector>
#include <iostream>

#include <set>


class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        for(auto &e:encoded)
        {
            ans.push_back(e^(*(ans.end()-1)));
        }
        return ans;
    }
};