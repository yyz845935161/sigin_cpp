#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string str;
    int ans=0;
    while(cin>>str)
    {
        
    for(auto e:str)
    {
        ans+= (int)(e-'0');
        if(ans>=10)
        {
            int temp1=ans/10;
            int temp2=ans%10;
            ans = temp1+temp2;
        }
        
        
    }
        
        cout<<ans<<endl;
        ans=0;
        }
    
}