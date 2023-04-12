#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include<math.h>
int main() {
    int a, b;
    string s1, s2;
    while (cin >> s1 >> s2 >> a >> b) {
        s1.append(b - s1.size(), 'a');
        s2.append(b - s2.size(), (char)('z' + 1));
        int count = 0;
        vector<int> v(b + 1);
        for (int i = 0; i < b; i++) {
            v[i] = s2[i] - s1[i];
            // cout<<v[i]<<endl;
        }


        for (int i = a; i <= b; i++) {
            for (int j = 0; j < i; j++) {
                count += v[j] * pow(26, i - j - 1);
            }

        }
        cout << (count - 1) % 1000007 << endl;
    }
}
// 64 位输出请用 printf("%lld")


// #include <iostream>
// using namespace std;
// string a, b;
// int max_len = 0;


// void find_max(int i, int j, int temp_len) {
//     if (i == a.size() || j == b.size()) {
//         if (temp_len > max_len) max_len = temp_len;
//         return;
//     }
//     if (a[i] == b[j]) {
//         temp_len++;
//         find_max(i + 1, j + 1, temp_len);
//     } else {
//         find_max(i, j + 1, temp_len);
//         find_max(i + 1, j, temp_len);
//     }
// }

// int main() {
//     while (cin >> a >> b) { // 注意 while 处理多个 case
//         int temp_len = 0;
//         max_len = 0;
//         find_max(0, 0,0);
//         cout << max_len << endl;
//     }
// }
// 64 位输出请用 printf("%lld")