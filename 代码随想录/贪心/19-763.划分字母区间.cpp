class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[256]  = { -1};
        int n = s.size();
        for(int i = 0; i < n; ++i)
        {
            hash[s[i]] = i;
        }
        vector<int> ans;
        int end = hash[s[0] ];
        int begin = 0;
        for(int i = 0; i < n; ++i)
        {
            if(i == end)
            {
                ans.push_back(end - begin + 1);
                begin = end + 1;
                if(i+1<n) end = hash[s[i+1]];
            }
            else
            {
                end = max(end,hash[s[i]]);
            }
        }
        return ans;

    }
};