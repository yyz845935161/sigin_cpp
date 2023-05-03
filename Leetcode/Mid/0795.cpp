class Solution {
public:

    void find_zi(vector<int>& nums,int left, int right,int i,int last,int& ans)
    {
        for(int j=last;j<i;j++)
        {   
            if(nums[j]<=right && nums[j]>=left)
            {
                ans+=(i-j);
            }
            else
            {
                for(int k=j+1;k<i;k++)
                {
                    if(nums[k]<=right && nums[k]>=left)
                    ans++;
                }
            }
        }

                
                
    }

    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
        int last = 0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>right)
            {
                find_zi(nums,left, right,i,last,ans);
                last = i+1;
                
            }
        }
        if(last==0)
        find_zi(nums,left, right,nums.size(),last,ans);
        else
        find_zi(nums,left, right,nums.size(),last,ans);
        return ans;

    }
};