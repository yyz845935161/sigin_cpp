class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        vector<int> ans;
        while(left<right)
        {
            while(left<right && nums[left] + nums[right] <target)
            {
                left++;
            }
            while(left<right && nums[left] + nums[right] > target)
            {
                right--;
            }
            if(nums[left] + nums[right] == target)
            {
                
                ans.push_back(nums[left]);
                ans.push_back(nums[right]);
                return ans;
            }
        }
        return ans;

    }
};