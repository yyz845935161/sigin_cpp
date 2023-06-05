#include <vector>
#include <iostream>

#include <set>



template<class T>
struct Less
{
public:
bool operator()(const T& a,const T& b) const
{
    return a>b;
}
};


class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]*=2;
                nums[i+1]=0;
            }
            if(nums[i]!=0) ans.push_back(nums[i]);
        }
        if(nums[nums.size()-1]!=0) ans.push_back(nums[nums.size()-1]);

        while(ans.size()!=nums.size()) ans.push_back(0);
        // sort(nums.begin(),nums.end(),Less<int>());
        
        
        return ans;
    }
};