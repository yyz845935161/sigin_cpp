#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    int findNthDigit(int n) {
        if(n<10) return n;

        int dig = 0;
        int dig_num = 0;
        
        long long num = 10;
        long long d = 10;
        long long  wei = 2;
        while( num + d*wei*9 <= n )
        {
            num+=d*9*wei;
            d*=10;
            wei++;
        }

        dig = (d + (n-num)/wei);
        dig_num = (n-num)%wei;
        cout<<dig<<" "<<dig_num<<endl;
        string str = to_string(dig);

        return str[dig_num]-'0';


    }
};



int main()
{
    Solution a;
    a.findNthDigit(11);

    return 0;
}