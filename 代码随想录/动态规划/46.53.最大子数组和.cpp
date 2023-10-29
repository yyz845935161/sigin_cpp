class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> v(nums.size());
        v[0] = nums[0];
        int ans = v[0];
        for(int i=1;i<nums.size();i++)
        {
            v[i] = max( v[i-1] + nums[i], nums[i]);
            if(v[i]>ans) ans = v[i];
        }
        return ans;
    }
};