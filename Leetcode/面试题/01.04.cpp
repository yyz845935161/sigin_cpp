#include <iostream>
#include <vector>
#include <string>
#include <map>
#include<unordered_map>
using namespace std;


class Solution {
public:
    bool canPermutePalindrome(string s) {
        int c[256] = {0};
        for(auto& e:s)
        {
            c[e]++;
        }
        int j=0;
        for(int i=0;i<256;i++)
        {
            if(c[i]%2==1)j++;
        }
        cout<<j;

        if(j<2) return true;
        return false;
    }
};