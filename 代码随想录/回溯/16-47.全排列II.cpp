class Solution {
public:

    void traceBack(vector<int>& nums ,int index,vector<int>& temp,vector<bool>& use,vector<vector<int>>& ans)
    {
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }

        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i]) != s.end()) continue;
            if(use[i]) continue;

            s.insert(nums[i]);
            use[i] = true;
            temp.push_back(nums[i]);
            traceBack(nums,0,temp,use,ans);
            temp.pop_back();
            use[i] = false;
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>> ans;
         vector<int> temp;
         vector<bool> use(nums.size(),false);
        sort(nums.begin(),nums.begin());
        traceBack(nums,0,temp,use,ans);
        return ans;

    }
};