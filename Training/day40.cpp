#include <iostream>
using namespace std;
#include <vector>
int main() {
    int a;
    vector<long long> v(21);
    v[1]=0;
    v[2]=1;
    for(int i=3;i<21;i++)
    {
        v[i]=(i-1)*(v[i-1]+v[i-2]);
    }
    while (cin >> a) { // 注意 while 处理多个 case
        cout<<v[a]<<endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")


#include <iostream>
#include <vector>
#include<math.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<int> v(n);
        vector<int> len(n,1);
        vector<int> fin(n);
        int ans=1;
        for(int i=0;i<n;i++)cin>>v[i];
        // len[0]=1;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(v[i]>v[j])
                {
                    len[i] = max(len[i],len[j]+1);
                    if(len[i]>ans) ans=len[i];
                }
            }
        }
        
        cout<<ans<<endl;
    }
}
// 64 位输出请用 printf("%lld")