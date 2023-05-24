#include <iostream>
#include <string>
using namespace std;
#include <vector>

// int main() {
//     string a;
//     vector<string> v;
//     getline(cin, a);
//     while (a.find(' ') != string::npos && !a.empty()) {
//         if (a[0] == '"') {
//             v.push_back(a.substr(1, a.find('"', 1)-1));
//             if(a.find('"', 1) + 2<a.size())
//             a = a.substr(a.find('"', 1) + 2, a.size());
//             else
//              a.clear();

//         } else {
//             v.push_back(a.substr(0, a.find(' ')));
//             a = a.substr(a.find(' ') + 1, a.size());
//         }

//         // cout<<a<<endl;
//     }
//     if(!a.empty())
//     v.push_back(a);

//     cout << v.size() << endl;
//     for (auto& e : v) {
//         cout << e << endl;
//     }

// }
// 64 位输出请用 printf("%lld")

// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


vector<int> find_yue(int n)
{
    vector<int> t;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)t.push_back(i);
    }
    return t;
}

// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


vector<int> find_yue(int n)
{
    vector<int> t;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {t.push_back(i);
            t.push_back(n/i);
        }
    }
    return t;
}

int main() {
    int n,m;
    while(cin >> n >> m)// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
    {
        vector<uint> v(2*m,-1);
        v[n]=0;
        for(int i=n;i<=m;i++)
        {
            if(v[i]==-1) continue;

            vector<int> temp = find_yue(i);
            for(auto& e:temp)
            {
                if(v[i]+1<v[i+e]) v[i+e] = v[i]+1;
            }
        }
        if(v[m]==-1) cout<<-1<<endl;
        else
        cout<<v[m]<<endl;
    }
}

