class Solution {
public:
    int rob(vector<int>& nums) {
            if(nums.size()<2)
            {
                return nums[0];
            }else if(nums.size()==2)
            {
                return max(nums[0],nums[1]);
            }

            vector<int> v1(nums.size());
            vector<int> v2(nums.size());

            v1[0] = nums[0];
            v1[1] = nums[0];

            v2[0] = 0;
            v2[1] = nums[1];

            for(int i=2;i<nums.size()-1;i++)
            {
                v1[i] = max(v1[i-2] + nums[i] , v1[i-1]);
                v2[i] = max(v2[i-2] + nums[i] , v2[i-1]);
            }

            v1[nums.size()-1] = v1[nums.size()-2];
            v2[nums.size()-1] = max(v2[nums.size()-3] + nums[nums.size()-1] , v2[nums.size()-2]);

            return max(v1[nums.size()-1], v2[nums.size()-1] );

    }
};