class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> vmax(nums.size());
        int m = nums[0];
        vmax[0] = nums[0];
        for(int i = 1;i < nums.size();i++)
        {
            vmax[i] = max(vmax[i-1] + nums[i] , nums[i] );
            m = vmax[i] > m ? vmax[i]:m;
        }
        return m;
    }
};