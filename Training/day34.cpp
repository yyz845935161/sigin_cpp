#include <iostream>
using namespace std;
#include<vector>
#include<string>

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<string> v(n);
        getchar();
        string ans;
        for (int i = 0; i < n; i++) {
            getline(cin, v[i]);
            if (v[i].find(',') != -1) {
                ans += "\"";
                ans += v[i];
                ans += "\"";
            } else {
                ans += v[i];
            }
            ans += ", ";
        }

        ans.erase(ans.end()-2,ans.end()-1);
        cout<<ans<<endl;;

    }
}
// 64 位输出请用 printf("%lld")

#include <iostream>
using namespace std;

int main() {
    int a;
    long long n[90];
    n[0]=1;
    n[1]=2;
    for(int i=2;i<90;i++)
    {
        n[i]=n[i-1]+n[i-2];
    }
    while (cin >> a) { // 注意 while 处理多个 case
        cout<<n[a-1]<<endl;
    }
}
// 64 位输出请用 printf("%lld")