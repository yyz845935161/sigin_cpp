#include <iostream>
#include <vector>
#include <string>
#include <map>
#include<unordered_map>
using namespace std;


class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(auto& e:s1) m1[e]++;
        for(auto& e:s2) m2[e]++;

        for(auto& e:s1) if(m2[e] != m1[e]) return false;
        for(auto& e:s2) if(m2[e] != m1[e]) return false;
        return true;
    }
};