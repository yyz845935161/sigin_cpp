//使用辅助muitiset  
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            s.insert(nums[i]);
        }
        ans.push_back( *(--s.end()));

        for(int i=k;i<nums.size();i++)
        {

            s.erase(s.find(nums[i-k]));
            s.insert(nums[i]);
            ans.push_back( *(--s.end()));
        }

        return ans;

    }
};