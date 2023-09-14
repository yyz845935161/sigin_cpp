class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left<right)
        {
            while(left<right && nums[left]%2 !=0)
            {
                left++;
            }
            while(left<right && nums[right]%2 ==0)
            {
                right--;
            }
            swap(nums[left],nums[right]);
        }
        // swap(nums[left],nums[right]);
        return nums;

    }
};