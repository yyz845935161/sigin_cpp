class Solution {
public:
    vector<string> ans;
    vector<string> temp;
    bool isUseful(const string& s)
    {
        if(s == "0") return true;
        if(s[0] == '0') return false;

        if(atol(s.c_str()) <=255) return true;
        return false;
    }

    void traceBack(const string& s, int startIndex, int cutTime)
    {
        if(startIndex >= s.size())
        {
            if(cutTime == 4)
            {
                string ts;
                for(int i = 0; i< temp.size();i++)
                {
                    ts+=temp[i];
                    ts+='.';
                }
                ts.pop_back();
                ans.push_back(ts);
            }
            return;
        }

        for(int i = startIndex + 1; i <= s.size(); i++)
        {
            string subs = s.substr(startIndex,i - startIndex);
            if( !isUseful(subs)) continue;

            temp.push_back(subs);
            
            traceBack(s, i, cutTime+1);
            temp.pop_back();
            
        }

    }
    vector<string> restoreIpAddresses(string s) {
        traceBack(s, 0, 0);
        return ans;
    }
};