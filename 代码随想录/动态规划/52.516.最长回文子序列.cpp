class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = n-1; i>=0 ;i--)
        {
            for(int j = i;j<n;j++)
            {
                if(s[i] == s[j])
                {
                    if(j-i == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else if(j - i == 1)
                    {
                        dp[i][j] = 2;
                    }
                    else
                    {
                        dp[i][j] = dp[i+1][j-1]+2;
                    }
                }
                else
                {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        //         for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }


        return dp[0][n-1];
    }
};