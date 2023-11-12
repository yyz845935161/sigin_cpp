class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;

    void traceBack(int& k,int& n, int indexStart)
    {
        if(temp.size() == k)
        {
            result.push_back(temp);
            return;
        }

        for(int i = indexStart;i <= n;i++)
        {
            temp.push_back(i);
            traceBack(k,n,i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        traceBack(k,n,1);
        return result;
    }
};