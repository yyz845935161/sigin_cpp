class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s1 = s.size();
        int s2 = t.size();
        vector<vector<int>> dp(s1+1,vector<int>(s2+1,0));
        for(int i = 0;i<=s2;i++)
        {
            dp[0][i] = 1;
        }

        for(int i = 1;i<=s1;i++)
        {
            for(int j = 1; j<=s2;j++)
            {
                if(s[i-1] == t[j-1]) 
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        return dp[s1][s2];
    }
};