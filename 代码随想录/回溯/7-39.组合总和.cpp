class Solution {
public:

    vector<vector<int>> ans;
    vector<int> temp;
    void traceBack(vector<int>& candidates,const int& target,int val, vector<int>& temp, int index)
    {
        if(target == val)
        {
            ans.push_back(temp);
            return ;
        }


        for(int i = index; i < candidates.size(); i++)
        {
            if(val +  candidates[i] > target) break;
            val+= candidates[i];
            temp.push_back(candidates[i]);
            traceBack(candidates,target,val,temp,i);

            temp.pop_back();
            val-= candidates[i];
        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        traceBack(candidates,target,0,temp,0);
        return ans;
    }
};