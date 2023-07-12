class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            ans+= (pow(-1,i)*  ((s[i])-'0') );
        }
        return ans;
    }
};