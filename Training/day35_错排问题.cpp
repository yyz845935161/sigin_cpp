#include <iostream>
using namespace std;
#include<unordered_map>
//最终得出公式n人都不获奖的概率h(n) = (n - 1) * (f(n - 1) + f(n - 2)) / (n!).
//a的名字没有被a拿到，有n - 1情况，此时又有
//b的名字被a拿到了有 f(n - 2)
//b的名字没有被a拿到  f(n - 1)
long long jie(int n) {
    long long a=1;
    while (n > 1) {
        a *= n;
        n--;
    }
    return a;
}

// int main() {
//     int a;
//     long long v[21];
//     v[0] = 0;
//     v[1] = 0;
//     v[2] = 1;
//     for (int i = 3; i < 21; i++) {
//         v[i] = (i - 1) * (v[i - 1] + v[i - 2]);
//     }

//     while (cin >> a) { // 注意 while 处理多个 case
//         double ans = (double)v[a] / (double)jie(a) * 100;
//         printf("%.2f%%\n", ans);


//     }
// }
// 64 位输出请用 printf("%lld")

#include <iostream>
#include <string>
#include<unordered_map>
using namespace std;

int main() {
    string a, b;
    while (getline(cin, a)) { // 注意 while 处理多个 case
        getline(cin, b);
        unordered_map<string, int> m;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == '\"') {
                string temp;
                i++;
                while (i < a.size() && a[i] != '\"') {
                    temp += a[i++];
                }
                m[temp]++;

            } else {
                string temp;
                while (i < a.size() && a[i] != ',') {
                    temp += a[i++];
                }
                m[temp]++;
            }
        }

        if (m[b] == 0) cout << "Important!" << endl;
        else cout << "Ignore" << endl;


    }
}
// 64 位输出请用 printf("%lld")