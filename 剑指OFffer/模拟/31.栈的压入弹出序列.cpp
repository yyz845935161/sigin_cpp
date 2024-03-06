class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;

        int i = 0;
        for(auto & e:popped)
        {
            if(!s.empty() && s.top() == e)
            {
                s.pop();
            }
            else
            {
                while( i < pushed.size() && pushed[i] != e)
                {
                    s.push(pushed[i++]);
                }
                if(i >= pushed.size())
                {
                    return false;
                }
                else
                {
                    i++;
                }
            }
        }
        return true;
    }
};