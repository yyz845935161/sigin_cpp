#include<iostream>
#include<vector>
using namespace std;
#include<unordered_map>

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        string s(flips.size(),'0');
        string con(flips.size(),'0');
        int ans=0;
        for(int i=0;i<flips.size();i++)
        {
            s[flips[i]-1] = '1';
            con[i]='1';
            // if(atoi(con)== atoi(s) )
            if(con == s)
            {
                ans++;
            }
        }

        return ans;
    }
};