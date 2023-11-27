class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-3; i++)
        {
            if(i>0 && nums[i] == nums[i-1] ) continue;
            for(int j = i + 1; j <  nums.size()-2; j++)
            {
                if(j > i + 1 && nums[j] == nums[j-1] ) continue;

                int left = j + 1;
                int right = nums.size()-1;
                while(left < right)
                {

                    if( (long long)nums[left] +  nums[right] + nums[i]  + nums[j]== target) 
                    {
                        result.push_back({nums[i], nums[j], nums[left++],nums[right--]});
                    }
                    else if((long long)nums[left] +  nums[right] + nums[i]  + nums[j] > target )
                    {
                        right--;
                    }
                    else
                    {
                        left++;
                    }
                    while( left !=  j + 1 &&  left < right && nums[left] == nums[left - 1]) left++;
                    while( right !=  nums.size()-1 &&  left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
        return result;
    }
};