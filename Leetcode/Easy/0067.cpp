#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size()>b.size())
        {
            swap(a,b);
        }
        
        int sa=a.size();
        int sb=b.size();
        int i=0;
        string ans;
        bool IsJin = false;
        while(i<b.size())
        {
            int j=(IsJin?1:0);
            int temp;
            if(i<a.size())
            temp = int(b[sb-i-1]-'0')+int(a[sa-i-1]-'0') + j;
            else
            temp = int(b[sb-i-1]-'0')+ j;
            cout<<temp;
            // printf("%c  ",temp);
            if(temp==0) 
            {ans+='0';
            IsJin = false;

            }
            else if(temp==1) 
            {
                ans+='1';
                IsJin = false;

            }
            else if(temp==2)
            {
                ans+='0';
                IsJin = true;
            }
            else
            {
                IsJin = true;
                ans+='1';
            }
            i++;
  
        }
        if(IsJin) ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};