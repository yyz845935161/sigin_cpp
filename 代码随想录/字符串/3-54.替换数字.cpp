#include <iostream>
#include <string>
using namespace std;


int main()
{
    string s;
    string result;
    getline(cin,s);
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] <= '9' && s[i] >= '0')
        {
            result+="number";
        }
        else
        {
            result+=s[i];
        }
    }
    
    cout<<result<<endl;
    
    
    
}