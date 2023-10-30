class Solution {
public:
    int numDistinct(string s, string t) {
        int ns = s.size();
        int nt = t.size();
        vector<vector<int>> dp(nt+1,vector<int>(ns+1,0));
        for(int i = 0 ;i<= ns ;i++)
        {
            dp[0][i] = 1;
        }
        

        for(int i = 1;i<=nt;i++)
        {
            for(int j = 1;j<=ns;j++)
            {
                if(s[j-1]==t[i-1])
                {
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                }
                else
                {
                    dp[i][j] = dp[i][j-1];
                }
                dp[i][j] %= 1000000007;
            }
        }

        // for(int i = 0;i<=nt;i++)
        // {
        //     for(int j = 0;j<=ns;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return dp[nt][ns];
    }
};