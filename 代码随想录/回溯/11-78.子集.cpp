class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void TraceBack(int indexStart, const vector<int>& nums)
    {
        result.push_back(path);
        for(int i = indexStart; i< nums.size(); i++)
        {
            path.push_back(nums[i]);
            TraceBack(i+1,nums);
            path.pop_back();
        }
    }   

    vector<vector<int>> subsets(vector<int>& nums) {
        // result.push_back(path);
        TraceBack(0,nums);
        return result;
        

    }
};