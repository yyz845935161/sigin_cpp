class Solution {
public:

    int ThreeMin(int a,int b,int c)
    {
        int temp;
        if(a>b) temp=b;
        else
        temp = a;

        if(temp >c) return c;
        else
        return temp;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans(n,vector<int>(n+2,INT_MAX));
        for(int i=0;i<n;i++)
        {
            ans[0][i+1] = matrix[0][i];
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][j+1] = matrix[i][j] + ThreeMin(ans[i-1][j+2],ans[i-1][j],ans[i-1][j+1]);
            }
        }
        int min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(ans[n-1][i+1] < min) min = ans[n-1][i+1];
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n+2;j++)
            {
                cout<<ans[i][j]<<' ';
            }
            cout<<endl;
        }


        return min;

    }
};