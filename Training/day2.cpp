// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    while (cin >>
            n) { // 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
        vector<int> v(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int i = 0;
        int count = 0;
        while (i < n) {
            if (v[i] < v[i + 1]) {
                while (i < n && v[i] <= v[i + 1]) {
                    i++;
                }
                count++;
                i++;

            } else if (v[i] == v[i + 1]) {
                i++;

            }

            else {
                while (i < n && v[i] >= v[i + 1]) {
                    i++;
                }
                count++;
                i++;
            }




        }
        cout << count << endl;

    }
}



// int main() {
//     string s;
//     while (getline(cin,s)) { // 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
//         reverse(s.begin(),s.end());
//         int begin=0;
//         for(int i=0;i<s.size();i++)
//         {
//             if(s[i]==' ')
//             {
//                 reverse(s.begin()+begin,s.begin()+i);
//                 begin=i+1;
//             }
//         }
//         reverse(s.begin()+begin,s.end());
//         cout<<s<<endl;
        
        
        
//     }
// }