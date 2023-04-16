// #include <iostream>
// using namespace std;
// #include<string>

// int main() {
//     string a;
//     while (getline(cin,a)) { // 注意 while 处理多个 case
//         // cout << a + b << endl;
//         string ans;
//         for(auto e:a)
//         {
//             if(e<='9'&& e>='0')
//             ans+=e;
//         }
//         cout<<ans<<endl;
//     }
// }
// // 64 位输出请用 printf("%lld")

#include <iostream>
using namespace std;
#include <vector>

int ans = INT16_MAX;

vector<string> map(10);

void find_path(int i, int j, int temp) {
    temp++;
    map[i][j] = '#';
    if (i == 9 && j == 8) {
        if (temp < ans)
            ans = temp;
    }

    if (i + 1 < 10 && map[i + 1][j] == '.')
        find_path(i + 1, j, temp);
    if (j + 1 < 10 && map[i ][j + 1] == '.')
        find_path(i, j + 1, temp);
    if (i - 1 >= 0 && map[i - 1][j] == '.')
        find_path(i - 1, j, temp);
    if (j - 1 >= 0 && map[i][j - 1] == '.')
        find_path(i, j - 1, temp);
    // map[i][j] = '.';

}

int main() {
    while (cin >> map[0]) {
        // 注意 while 处理多个 case
        int temp;
        ans = INT16_MAX;
        // cout << ans << endl;
        for (int i = 1; i < 10; i++) {
                    cin >> map[i];
        }

        find_path( 0, 1, 1);
        cout << ans-2 << endl;
    }
}
// 64 位输出请用 printf("%lld")