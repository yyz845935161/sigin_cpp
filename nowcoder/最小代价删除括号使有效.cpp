#include <cctype>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

#include <cctype>
#include <stack>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string minRemoveToMakeValid(string s) {
        // write code here
        stack<pair<char,int>> st;

        for(int i=0;i<=s.size();i++ )
        {
            if(!isalpha(s[i]))
            {
                if(!st.empty())
                {
                    if((s[i] == ')' && st.top().first == '(') || (s[i] == ']' && st.top().first == '[') ||(s[i] == '}' && st.top().first == '{')  )
                    {
                        st.pop();
                    }
                    else {
                    st.push({s[i],i});
                }

                }
                else {
                    st.push({s[i],i});
                }
            }
        }
        stack<pair<char,int>> st1;
        stack<pair<char,int>> st2;
        stack<pair<char,int>> st3;
        while (!st.empty()) 
        {
            pair<char,int> c = st.top();
            st.pop();
            if(c.first == '(' || c.first == ')' )
            {
                if(!st1.empty() && c.first == '(' && st1.top().first == ')' )
                {
                    st1.pop();
                }
                else
                st1.push(c);
            }
            else if( c.first == '[' || c.first == ']')
            {
                if(!st2.empty() && c.first == '[' && st2.top().first == ']' )
                {
                    st2.pop();
                }
                else
                st2.push(c);
            }
            else if( c.first == '{' || c.first == '}')
            {
                if(!st3.empty() && c.first == '{' && st3.top().first == '}' )
                {
                    st3.pop();
                }
                else
                st3.push(c);
            }
        }
        pair<char,int> c;
        while (!st1.empty()) {
            c = st1.top();
            st1.pop();
            s[c.second] = '@';
        }
        while (!st2.empty()) {
            c = st2.top();
            st2.pop();
            s[c.second] = '@';
        }
        while (!st3.empty()) {
            c = st3.top();
            st3.pop();
            s[c.second] = '@';
        }
        
        string ans;
        for(auto& e:s)
        {
            if(e!='@') ans+= e;
        }
        return ans;



    }
};