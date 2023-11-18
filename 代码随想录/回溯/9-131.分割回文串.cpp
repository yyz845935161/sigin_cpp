class Solution {
public:
    vector<string> temp;
    vector<vector<string>> ans;
    bool IsH(string s)
    {
        if(s.size()<=1) return true;

        for(int i = 0; i<=s.size()/2;i++)
        {
            if(s[i]!= s[s.size()-i-1]) return false;
        }
        return true;
    }

    void traceBack(const string& s, int index)
    {
        string right = s.substr(index, s.size()-index);
        if( IsH(right) && !right.empty())
        {
            temp.push_back(right);
            ans.push_back(temp);
            temp.pop_back();
            // return;
        }

        for(int i = index; i < s.size(); i++)
        {
            string left = s.substr(index, i - index +1);
            if(IsH(left))
            {
                temp.push_back(left);
                traceBack(s, i+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        if(s.empty()) return ans;
        traceBack(s, 0);
        return ans;
    }
};



class Solution {
public:
    vector<string> temp;
    vector<vector<string>> ans;
    bool IsH(const string& s,int start, int end)
    {
        for(int i = start; i<=end;i++)
        {
            if(s[start++]!= s[end--]) return false;
        }
        return true;
    }

    void traceBack(const string& s, int index)
    {
        if( index >= s.size())
        {
            ans.push_back(temp);
            return ;
        }

        for(int i = index; i <= s.size(); i++)
        {
            if(IsH(s,index, i))
            {
                string left = s.substr(index, i - index + 1);
                temp.push_back(left);
            }
            else
            {
                continue;
            }
            traceBack(s, i+1);
            temp.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        if(s.empty()) return ans;
        traceBack(s, 0);
        return ans;
    }
};