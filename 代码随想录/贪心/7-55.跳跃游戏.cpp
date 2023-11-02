class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ans = nums[0];
        for(int i = 0;i <=ans;i++)
        {
            cout<< ans<<endl;
            if(nums[i] + i>ans)
            {
                ans = nums[i] + i;
            }

            if(ans >= nums.size()-1)
            {
                return true;
            }
        }

        return false;
    }
};