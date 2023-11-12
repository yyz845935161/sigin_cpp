class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string temp = to_string(n);

        int flag =temp.size() ;
        for(int i = temp.size()-1; i>0;i--)
        {
            if(temp[i] < temp[i-1])
            {
                flag = i;
                temp[i-1] = temp[i-1] -1;
            }
        }
        for(int i = flag; i< temp.size(); i++)
        {
            temp[i] = '9';
        }

        return atoi(temp.c_str());
    }
};