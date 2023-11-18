class Solution {
public:
    vector<vector<int>> ans;
    pair<vector<int>,int> path = {{},0};

    void traceBack(int k, int n, int index)
    {
        if(path.first.size() == k )
        {
            if(path.second == n)
            ans.push_back(path.first);
            return ;
        }

        for(int i = index; i <= 9 - (k - path.first.size()) + 1; i++)
        {
            if(path.second + i > n ) break;
            path.first.push_back(i);
            path.second+=i;
            traceBack(k,n,i+1);
            path.second-=i;
            path.first.pop_back();
        }
    }


    vector<vector<int>> combinationSum3(int k, int n) {
            traceBack(k,n, 1);
            return ans;
    }
};