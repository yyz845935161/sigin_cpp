class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if(finalSum&1) return ans;
        finalSum/=2;
        long long val = finalSum;
        cout<<val;
        for(int j=1;j<=val;j++)
        {
            ans.push_back(j*2);
            val-=j;
        }
        if(val!=0)
        {
            ans.back() += (val*2);
        }

        return ans;


        


        
    }
};