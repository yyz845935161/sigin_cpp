/*
    使用新空间：
        创建新字符串，遇到空格就+=%20;
    原地修改：
        find查找修改
*/

//使用新空间：
#include<iostream>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        string temp;
        for(auto& e:s)
        {
            if(e==' ')
            {
                temp+="%20";
            }
            else
            {
                temp+=e;
            }
        }
        return temp;

    }
};

class Solution {
public:
    string replaceSpace(string s) {
        while(s.find(" ")!=-1)
        {
            int index = s.find(" ");
            s.erase(index,1);
            s.insert(index,"%20");
        }
        return s;

    }
};