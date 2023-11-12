class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b )->bool{
            return a[0] < b[0];
        });

        int right = intervals[0][1];
        int left = intervals[0][0];
        vector<vector<int>> v;
        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] <= right)
            {
                right = max(right, intervals[i][1]);
            }
            else
            {
                v.push_back({left, right});
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }
        v.push_back({left, right});

        return v;
    }
};