class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        int ans=0;
        for(auto e:grid)
        {
            for(auto g:e)
            {
                v.push_back(g);
            }
        }

        sort(v.begin(),v.end());
        int n=v.size();
        int mid =v[n/2];
        cout<<mid;
        for(int i=0; i<n;i++)
        {
            if( (mid-v[i])  % x !=0) return -1;
            else
            {
                ans +=   abs(mid - v[i])/x;
            }
        }
        return ans;
    }
};