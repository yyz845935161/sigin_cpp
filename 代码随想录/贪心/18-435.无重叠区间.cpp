class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b)->bool{
            // if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        });

        int ans = 0;
        int right = intervals[0][1];
        for(int i = 1; i<intervals.size(); i++)
        {
            if(intervals[i][0] >= right){ right = intervals[i][1];}
            else
            {
                ans++;
                right = min(right, intervals[i][1]);
            }
        }
        return ans;
    }
};