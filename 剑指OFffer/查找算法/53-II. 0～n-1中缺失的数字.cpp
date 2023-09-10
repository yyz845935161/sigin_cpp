class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right)
        {
            int m = (left+right)/2;
            if(nums[m] == m)
            {
                left = m+1;
            }
            else
            {
                right = m-1;
            }

        }
        return left;
    }
};