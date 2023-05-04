#include <vector>
#include <iostream>

#include <map>
using namespace std;


class Solution {
public:
    bool isArpth(const char& c)
    {
        if((c<='z' && c>='a')  ||(c<='Z' && c>='A') )return true;
        return false;
    }


    int lengthOfLastWord(string s) {
        while(!(isArpth(s[s.size()-1])))
        {
            s.erase(s.size()-1);
        }
        while(!(isArpth(s[0])))
        {
            s.erase(s.begin());
        }

        if(s.find(' ') == -1)
        {
            return s.size();
        }


    
        string temp = s.substr(s.rfind(' ')+1,s.size()-1);
        cout<<temp;
        return temp.size();

    }
};