class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int count = 0;
        for(int i = n-1; i>=0 ;i--)
        {
            for(int j = i;j<n;j++)
            {
                if(s[i] == s[j])
                {
                    if(j-i<=1)
                    {
                        dp[i][j] = 1;
                        count++;
                    }
                    else
                    {
                        if(dp[i+1][j-1])
                        {
                            count++;
                            dp[i][j] = 1;
                        }
                    }
                }
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return count;
    }
};