#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:

    string add(string num1,string num2)
    {
        string ans;
        if(num1.size()<num2.size())
        {
            swap(num1,num2);
        }
        int jin = 0;
        for(int i=0;i<num1.size();i++)
        {

            int b = 0;
            if(num2.size()-1<i)
            {
                b= 0;
            }
            else
            {
                
                b=  num2[num2.size()-i-1] - '0';
            }
            int temp = num1[num1.size()-i-1]  - '0' + jin + b;
            int g = temp%10;
            jin = temp/10;
            // ans.insert(ans.begin(),char(g)+'0');
            ans+=(char(g)+'0');
        }
        // if(jin) ans.insert(ans.begin(),'1');
        if(jin) ans+='1';
        reverse(ans.begin(),ans.end());
        return ans;

    }


    string multiply(string num1, string num2) {

        if(num1=="0" || num2 == "0") return "0";


        int n1s = num1.size();
        int n2s = num2.size();
        vector<string> v;
        string ans="0";
        for(int i=0;i<num1.size();i++)
        {
            int jin=0;
            int cur=0;
            string temp;
            temp.insert(temp.end(),i,'0');
            for(int j=0;j<num2.size();j++)
            {
                // int temp = num1[n1s-1-i];
                int tempi = (num1[n1s-1-i] - '0') * (num2[n2s-1-j] - '0') + jin;
                
                int g = tempi%10;
                jin = tempi/10;

                temp+= (char(g)+'0');
            }
            if(jin !=0)
            {
                temp+= (char(jin)+'0');
                jin = 0;
            }
            
            reverse(temp.begin(),temp.end());
            v.push_back(temp);
            cout<<temp<<endl;
        }
        for(auto e:v)
        {
            ans=add(ans,e);
        }
        return ans;
    }
};