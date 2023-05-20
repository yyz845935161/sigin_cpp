
#include<iostream>
#include<vector>
using namespace std;
#include<unordered_map>

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string,int> m;
        vector<string> ans;
        for(auto &e:names)
        {
            if(m.find(e)==m.end())
            {
                // cout<<e;
                ans.push_back(e);
                m[e]++;
                // if(e[e.size()-1])

            }
            else
            {
                int index = m[e];
                string temp = e + "("+ to_string(index)+")";
                while(m.find(temp)!=m.end())
                {
                    index++;
                    temp = e + "("+ to_string(index)+")";
                }
                ans.push_back(temp);
                m[temp]++;
                m[e]++;
            }
        }

        return ans;
    }
};