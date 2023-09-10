

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<double>> ans(n+1,vector<double>(n*6-n+1,0));
        for(int i=0;i<6;i++)
        {
            ans[1][i] = 1.0/6.0;
        }

        for(int i =2 ; i <= n;i++)
        {
            for(int j=0; j<(i-1)*6-(i-1)+1;j++)
            {
                for(int k=0;k<6;k++)
                {
                    ans[i][j+k] += ans[i-1][j]/6.0;
                }
            }
        }
        return ans[n];

    }
};