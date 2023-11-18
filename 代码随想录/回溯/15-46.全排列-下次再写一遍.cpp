class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
    vector<bool> used;

    void traceBack(vector<int>& nums, int n)
    {
        if(path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(used[(i+n)% nums.size()]) continue;
            path.push_back(nums[(i+n)% nums.size()]);
            used[(i+n)% nums.size()] = true;
            traceBack(nums, i+n+1);
            path.pop_back();
            used[(i+n)% nums.size()] = false;
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> temp(6,false);
        used = std::move(temp);
        traceBack(nums, 0);
        return result;
    }
};