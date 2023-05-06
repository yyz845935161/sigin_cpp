#include <iostream>
#include <vector>
#include <string>
#include <map>
#include<unordered_map>
using namespace std;


class Solution {
public:
    string replaceSpaces(string S, int length) {
        string ans;
        for(int i=0;i<length;i++)
        {
            if(S[i]==' ') ans+="%20";
            else ans+=S[i];
        }
        return ans;
    }
};