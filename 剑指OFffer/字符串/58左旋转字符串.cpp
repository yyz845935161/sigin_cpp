class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string ans;
        for(int i=0;i<s.size();i++)
        {
            ans+= s[n%s.size()];
            n++;
        }
        return ans;
    }
};