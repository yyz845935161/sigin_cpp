class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;

        int max = 0;
        vector<int> v(prices.size());
        v[0] = 0;
        int mini = 0;
        for(int i=1;i<prices.size();i++)
        {
            

            if(prices[i] - prices[mini] > max)
            {
                max = prices[i] - prices[mini];
            }

            if(prices[mini] > prices[i])
            {
                mini = i;
            }
        }
        return max;
    }
};