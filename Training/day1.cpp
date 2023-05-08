#include <iostream>
using namespace std;

// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    while (cin >>
            n) { // 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
        vector<int> v(3 * n);
        for (int i = 0; i < 3 * n; i++) {
            cin >> v[i];
        }
        size_t ans = 0;
        sort(v.begin(), v.end());
        for (int i = n; i < 3 * n; i += 2) {
            ans += v[i];
        }
        cout << ans << endl;

    }
}





// int main()
// {
//     string a,b;
//     while(getline(cin,a))
//     {
//         getline(cin,b);
//         char c[256]={0};
//         for(auto& e:b)
//         {
//             c[e]++;
//         }
        
//         for(auto& e:a)
//         {
//             if(c[e]==0)
//                 cout<<e;
//         }
//         cout<<endl;
//     }
// }