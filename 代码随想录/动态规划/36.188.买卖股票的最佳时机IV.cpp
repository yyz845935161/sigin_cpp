class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2*k,0));
        for(int i=0;i<2*k;i+=2)
        {
            dp[0][i] = -prices[0];
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<2*k; j+=2)
            {
                if(j!=0)
                {
                    dp[i][j] = max(dp[i-1][j-1] - prices[i], dp[i-1][j]); 
                    dp[i][j+1] = max(dp[i-1][j] + prices[i], dp[i-1][j+1]);
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], -prices[i]);
                    dp[i][j+1] = max(dp[i-1][j]+prices[i], dp[i-1][j+1]);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<2*k; j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }

        return dp[n-1][2*k-1];

    }
};