#include <vector>
#include <iostream>

#include <set>



// class Solution {
// public:
//     int unequalTriplets(vector<int>& nums) {
//         set<int> s;
//         for(auto & e:nums)
//         {
//             s.insert(e);
//         }
//         int n = s.size();
//         if(n < 3) return 0;
//         if(n==3) return 1;

//         int ans=1;
//         int add=0;
//         for(int i=3;i<n;i++)
//         {
//             add+=i;
//             ans+=add;
//         }

//         return ans;
//     }
// };


class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(nums[i]!=nums[j] && nums[i]!=nums[k] && nums[k]!=nums[j])ans++;
                }
            }
        }
        return ans;
    }
};