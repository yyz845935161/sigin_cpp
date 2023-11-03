//复杂度抄了
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> dp(n, 1);
        int ans = n;
        for(int i = 1;i<n;i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                dp[i] = dp[i-1]+1;
                ans+= (dp[i] -1);
            }
            else if(ratings[i] == ratings[i-1])
            {
                // dp[i] = dp[i-1];
                // ans+= (dp[i] -1);
            }
            else if(ratings[i] < ratings[i-1])
            {
                int j = i-1;
                while(j>=0 &&  ratings[j+1]<ratings[j] && dp[j] == dp[j+1])
                {
                    dp[j--]++;
                    ans++;
                }
            }
        }

        // for(int i = 0;i<n;i++)
        // {
        //     cout<<dp[i]<<" ";
        // }
        return ans;
    }
};





//贪心！！
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> dp(n, 1);
        // d[0] = 1;
        for(int i = 1;i<n;i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                dp[i] = dp[i-1] +1;
            }
        }
        int ans = 0;
        for(int i = n-2;i>=0;i--)
        {
            if(ratings[i] > ratings[i+1])
            {
                dp[i] = max(dp[i], dp[i+1] +1);
            }
        }


        for(int i = 0;i<n;i++)
        {
            cout<<dp[i]<<" ";
            ans+=dp[i];
        }
        return ans;
    }
};