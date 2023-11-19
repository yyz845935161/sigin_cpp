class Solution {
public:

    vector<int> path;
    vector<vector<int>> result;

    void TraceBack(int indexStart, const vector<int>& nums)
    {
        result.push_back(path);
        if(indexStart >= nums.size()) return;


        int temp = 11;
        for(int i = indexStart; i< nums.size(); i++)
        {
            if(temp == nums[i]) continue;
            path.push_back(nums[i]);
            TraceBack(i+1,nums);
            path.pop_back();
            temp = nums[i];
        }
    }   

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // result.push_back(path);
        sort(nums.begin(),nums.end());
        TraceBack(0,nums);
        return result;
        
    }
};


