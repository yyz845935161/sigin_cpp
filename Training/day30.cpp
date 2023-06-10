// 本题为考试多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    //freopen("1.in","r",stdin);
    int n,ans = 0;
    string s;
    while(getline(cin,s))
    {
        for(auto & e:s)
        {
            
            if(e == ' ')
            {
                continue;
            }
            else if(e - 5 < 'A')
            {
                e = e + 26 - 5;
            }
            else
            {
                e-=5;
            }
        }
        cout << s << endl;
    }

    
    return 0;
}

// 本题为考试多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int main(){
    //freopen("1.in","r",stdin);
    int n = 0;
    while(cin>>n)
    {
        int ans=0;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                ans++;
                while(n%i==0)
                {
                    n/=i;
                }
            }
            
        }
        if(n!=1) ans++;
        cout<<ans<<endl;
    }

    
    return 0;
}