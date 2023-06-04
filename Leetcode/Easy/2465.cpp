#include <vector>
#include <iostream>

#include <set>


class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        set<double> ans;
        sort(nums.begin(),nums.end());
        int len = nums.size();
        for(int i=0;i<nums.size();i++)
        {
            ans.insert(nums[i]+nums[len-i-1]);
        }

        return ans.size();
    }
};