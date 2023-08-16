class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int temp =  nums[0]; 
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==temp)
            {
                count++;
            }
            else
            {
                count--;
                if(count<0) 
                {
                    temp=nums[i];
                    count=1;
                }
            }
        }
        return temp;

    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int temp =  0; 
        int count = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]==temp)
            {
                count++;
            }
            else
            {
                count--;
                if(count<0)
                {
                    temp = nums[i];
                    count=1;
                }
            }
        }
        return temp;

    }
};