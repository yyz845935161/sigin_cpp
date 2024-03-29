class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size()-1;
        vector<vector<int>> dp(prices.size(), vector<int>(4,0));
        dp[0][0] = -prices[0];
        for(int i = 1; i<prices.size();i++)
        {
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][1],dp[i-1][3]) - prices[i] );
            dp[i][1] = max(dp[i-1][1], dp[i-1][3]);
            dp[i][2] = dp[i-1][0] + prices[i];
            dp[i][3] = dp[i-1][2];
        }

        return max(max(dp[n][1],dp[n][2]),dp[n][3]);
    }
};