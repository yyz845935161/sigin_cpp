class Solution {
public:
    void dfs_string(const string& s,int i,vector<bool>& is_use,string temp)
    {
    //     if(i==s.size())
    //     {
    //         return;
    //     }
        if(temp.size()==s.size())
        {
            ans.insert(temp);
            return;
        }

        for(int j = 0;j<s.size();j++)
        {
            if( is_use[(j+i)%s.size()] == false )
            {
                temp+=s[(j+i)%s.size()];
                is_use[(j+i)%s.size()] = true;

                dfs_string(s,j+1,is_use,temp);
                temp.pop_back();
                is_use[(j+i)%s.size()] = false;
            }

            
        }

    }

    vector<string> permutation(string s) {
        vector<bool> is_use(s.size(),false);
        string temp;    
        dfs_string(s,0,is_use,temp);

        vector<string> a;
        for(auto& e:ans)
        {
            a.push_back(e);
        }

        return a;

    }
    // vector<bool> is_use;
    set<string> ans;
};