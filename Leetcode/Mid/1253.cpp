class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        int temp1=0;
        int temp2=0;
        vector<vector<int>> ans(2,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            if(colsum[i]==0)
            {
                ans[0][i]=0;
                ans[1][i]=0;
            }
            else if(colsum[i]==2)
            {
                ans[0][i]=1;
                ans[1][i]=1;
                temp1+=1;
                temp2+=1;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(ans[0][i]==-1)
            {
                if(temp1<upper)
                {
                    ans[0][i]=1;
                    ans[1][i]=0;
                    temp1++;
                }
                else
                {
                    ans[0][i]=0;
                    ans[1][i]=1;
                    temp2++;
                }
            }
        }

        if(temp1!=upper || temp2!=lower) ans.clear();
        return ans;
    }
};