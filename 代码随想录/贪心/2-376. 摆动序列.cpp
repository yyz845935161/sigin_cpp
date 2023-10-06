class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int temp = 0;
        int ans = 1;
        if(nums.size() <=1) return nums.size();

        int i = 1;
        while(i < nums.size())
        {
            while(i < nums.size() && nums[i] == nums[i-1])
            {
                i++;
            }

            if(i < nums.size() && nums[i] < nums[i-1] )
            {
                ans++;
                while( i < nums.size() && nums[i] <= nums[i-1])
                {
                    i++;
                }
            }
            if(i < nums.size() && nums[i] > nums[i-1] )
            {
                ans++;
                while(i < nums.size() && nums[i]>= nums[i-1])
                {
                    i++;
                }
            }
            
        }

        return ans;

        
    }
};