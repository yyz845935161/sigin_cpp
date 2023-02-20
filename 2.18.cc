#include<iostream>
using namespace std;
#include<vector>
#include<stack>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<int> _st;
        for(size_t i = 0;i<tokens.size();i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                
                int right = _st.top();
                _st.pop();
                int left = _st.top();
                _st.pop();

                switch(tokens[i][0])
                {
                    case '+':
                        _st.push(left+right);
                        break;
                    case '-':
                        _st.push(left-right);
                        break;
                    case '*':
                        _st.push(left*right);
                        break;
                     case '/':
                        _st.push(left/right);
                        break;
                }


            }

            else _st.push(stoi(tokens[i]));

        }
        return _st.top();


    }
};