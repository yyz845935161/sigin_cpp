// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>

int DAYNUM[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool IsRun(int year)
{
    if((year%4==0 && year%100!=0) || year%400==0)
    {
        return true;
    }
    else
        return false;
}

using namespace std;
// int main() {
//     int y,m,d;
//     while(cin >> y >> m >>d)// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
//     {
//         if(IsRun(y))
//         {
//             DAYNUM[2]=29;
//         }
//         else
//         {
//             DAYNUM[2]=28;
//         }
//     }
//     int ans=0;
//     for(int i=1;i<m;i++)
//     {
//         ans+=DAYNUM[i];
//     }
//     ans+=d;
//     cout<<ans;
//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getLuckPacket(vector<int>&x ,int n ,int pos, int sum, int multi,int & ans)
{
    for(int i=pos;i<n;i++)
    {
        sum+=x[i];
        multi*=x[i];
        if(sum>multi) 
        {
            ans++;
             getLuckPacket(x , n ,i+1,sum,multi, ans);
        }
        else if(x[i] == 1)
        {
            getLuckPacket(x , n ,i+1,sum,multi, ans);
        }
        else
            break;
        
        while(i<n-1 && x[i]==x[i+1])
            i++;
        sum-=x[i];
        multi/=x[i];
        
    }
}


int main() {
    int n;
    while(cin >>n)// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
    {
        vector<int> x(n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>x[i];
        }
        sort(x.begin(),x.end());
        getLuckPacket(x , n ,0,0,1, ans);
        cout<<ans<<endl;
    }
    return 0;
}