class Solution {
public:

    int Add(int a)
    {
        int ans=0;
        while(a)
        {
            ans+= (a%10);
            a/=10;
        }
        return ans;
    }

    void DfsRang(vector<vector<int>>& v,int& m, int& n, int& k,int i,int j,int& ans)
    {
        if(i>=m || i<0 || j>=n || j<0 )
        {
            return;
        }
        if(v[i][j] == 0 ) return ;
        if(Add(i) + Add(j) <=k)
        {
            ans++;
            v[i][j] = 0;
            DfsRang(v,m, n, k,i+1,j,ans);
            DfsRang(v,m, n, k,i,j+1,ans);
            DfsRang(v,m, n, k,i-1,j,ans);
            DfsRang(v,m, n, k,i,j-1,ans);
        }
    }


    int movingCount(int m, int n, int k) {
        int ans=0;
        vector<vector<int>> v(m,vector<int>(n,1));
        DfsRang(v,m, n, k,0,0,ans);
        
        return ans;

    }
};