#include <queue>
#include <iostream>
using namespace std;



class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
//         nums.push_back(-1);

        // if(n==1)
        // {
        //     if(nums[0]<1) return 1;
        //     else if(nums[0]==1) return 2;
        //     else
        //     return 1;
        // }

        for(int i=0;i<n;i++)
        {
            while(nums[i]>=1 && nums[i]<n && nums[i]!=nums[nums[i]-1])
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1) return i+1;
        }

        return n+1;
    }
};
