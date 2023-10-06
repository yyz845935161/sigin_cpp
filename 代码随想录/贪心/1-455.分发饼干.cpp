class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int gi = 0;
        int si = 0;
        int ans = 0;
        while(gi < g.size() && si < s.size() )
        {
            while(gi < g.size() && si < s.size() && s[si] < g[gi])
            {
                si++;
            }

            if(gi < g.size() && si < s.size() && s[si] >= g[gi])
            {
                si++;
                gi++;
                ans++;
            }

        }
        return ans;
    }
};