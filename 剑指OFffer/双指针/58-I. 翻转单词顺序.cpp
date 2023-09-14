class Solution {
public:

    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        string ans;
        int begin = 0;
        int end = 0;
        while(end<s.size())
        {
            while(end<s.size() && s[end]== ' ')
            {
                end++;
            }
            begin = end;
            while(end<s.size() && s[end]!=' ')
            {
                end++;
            }
            if(end == begin) break;
            string temp = s.substr(begin,end-begin);
            reverse(temp.begin(),temp.end());
            ans+=temp + " ";
        }

        
        return ans.substr(0,ans.size()-1);

    }
};