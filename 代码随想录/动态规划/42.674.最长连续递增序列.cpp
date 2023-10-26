class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        int ans = 1;
        dp[0] = 1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                dp[i]=dp[i-1]+1;
                if(dp[i]>ans) ans = dp[i];
            }
            else
            {
                dp[i] = 1;
            }
        }
        return ans;
    }
};