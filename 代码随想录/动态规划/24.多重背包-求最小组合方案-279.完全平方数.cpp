class Solution {
public:
    int numSquares(int n) {
        vector<int> num;
        for(int i=1;pow(i,2)<=n;i++)
        {
            num.push_back(pow(i,2));
        }

        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i=0;i<num.size();i++)
        {
            for(int j=num[i];j<=n;j++)
            {
                dp[j] = min(dp[j- num[i]]+1, dp[j] );
            }
        }
        // if(dp[n]== INT_MAX)
        return dp[n];
    }
};