struct AbsLess
{
    bool operator()(const int &a,const int &b)
    {
        return abs(a) > abs(b);
    }
};


class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(), AbsLess());
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            if(k != 0)
            {
                if(nums[i] < 0)
                {
                    nums[i] = -nums[i];
                    k--;
                }
            }
            ans+= nums[i];
        }

        if(k%2==1)
        {
            ans-= 2*nums[n-1];
        }
        return ans;

    }
};