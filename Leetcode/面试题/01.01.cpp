#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    bool isUnique(string astr) {
        char c[256]={0};
        for(auto& e:astr)
        {
            c[e]++;
            if(c[e]>1) return false;
        }
        return true;
    }
};