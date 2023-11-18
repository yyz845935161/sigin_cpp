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

        int flag = -1;
        for(int i = index; i < candidates.size(); i++)
        {
            if(val +  candidates[i] > target) break;
            if(candidates[i] == flag) continue;

            val+= candidates[i];
            temp.push_back(candidates[i]);
            traceBack(candidates,target,val,temp,i+1);
            temp.pop_back();
            val-= candidates[i];
            flag = candidates[i];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        traceBack(candidates,target,0,temp,0);
        return ans;
    }
};