#include <any>
#include <iostream>
#include <cstdio>

using namespace std;

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        
        int ans=0;
        while(n/3)
        {
            int temp = n/3;
            ans += temp;
            n%=3;
            n+=temp;
        }
        if(n==2) ans++;
        cout<<ans<<endl;

    }
    
    return 0;
}



int main(){
    
    string s1,s2;
    cin>>s1>>s2;
    string ans;
    
    if(s1.size()>s2.size()) swap(s1, s2);


    for(int i=0;i<s1.size();i++)
    {
        for(int j=0;j<s2.size();j++)
        {
            
            if(s2[j]==s1[i])
            {
                int tempi=i;
                int tempj=j;
                int len=1;
                while(tempi+1 < s1.size() && tempj+1 < s2.size() && s2[tempj+1]==s1[tempi+1] )
                {
                    len++;
                    tempi++;
                    tempj++;
                }
                if(len>ans.size())
                {
                    string  tempstr(s1.begin()+i,s1.begin()+tempi+1); 
                    ans = tempstr;
                }
                
            }
        }
          
    }
    cout<<ans;

    
    return 0;
}