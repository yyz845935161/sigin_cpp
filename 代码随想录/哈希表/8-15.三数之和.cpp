
//双指针，同时定了两个，移动一个，不可行
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size()-1;
        vector<vector<int>>  result;
        while(left < right)
        {
            while(left > 0 && nums[left -1] == nums[left]) left++;
            while(right < nums.size()-2 && nums[right] == nums[right+1]) right--;

            int i;
            for(i = left + 1; i < right; i++)
            {
                if( nums[left] +  nums[right] + nums[i] == 0)
                {
                    result.push_back({nums[left],nums[right],nums[i]});
                }
                else if(nums[left] +  nums[right] + nums[i] > 0 )
                {
                    right--;
                }
                
            }
            if(right == i) left++;
           
        }

        return result;
    }
};



//双指针，只能定一个，移动两个
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>  result;
        for(int i = 0; i < nums.size()-2; i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int left = i + 1;
            int right = nums.size()-1;
            while(left < right)
            {

                if( nums[left] +  nums[right] + nums[i] == 0) 
                {
                    result.push_back({nums[left++],nums[right--],nums[i]});
                }
                else if(nums[left] +  nums[right] + nums[i] > 0 )
                {
                    right--;
                }
                else
                {
                    left++;
                }
                while( left !=  i + 1 &&  left < right && nums[left] == nums[left - 1]) left++;
                while( right !=  nums.size()-1 &&  left < right && nums[right] == nums[right + 1]) right--;
            }

        }



        return result;
    }
};