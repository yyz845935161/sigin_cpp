// #include <iostream>
// #include <vector>
// using namespace std;

// int  solve(const vector<vector<char>>& map)
// {
//     int ad = 0, mul = 0;
//     for (int i = 0; i < 20; i++) {
//         for (int j = 0; j < 20; j++) {
//             if (map[i][j] == '.') {
//                 ad = 0;
//                 mul = 0;
//                 continue;
//             } else if (map[i][j] == '+') {
//                 mul = 0;
//                 ad++;
//             } else if (map[i][j] == '*') {
//                 mul++;
//                 ad = 0;
//             }
//             if (ad == 5 || mul == 5) {
//                 cout << "Yes" << endl;
//                 return 0;
//             }

//         }
//         ad = 0;
//         mul = 0;
//     }

//     for (int i = 0; i < 20; i++) {
//         for (int j = 0; j < 20; j++) {
//             if (map[j][i] == '.') {
//                 ad = 0;
//                 mul = 0;
//                 continue;
//             } else if (map[j][i] == '+') {
//                 mul = 0;
//                 ad++;
//             } else if (map[j][i] == '*') {
//                 mul++;
//                 ad = 0;
//             }
//             if (ad == 5 || mul == 5) {
//                 cout << "Yes" << endl;
//                 return 0;
//             }

//         }
//         ad = 0;
//         mul = 0;

//     }

//     for (int i = 0; i < 20; i++) {
//         for(int j=0;j<20;j++)
//         {
//             if(i+j>=20) break;

//             if (map[j][i+j] == '.') {
//                 ad = 0;
//                 mul = 0;
//                 continue;
//             } else if (map[j][i+j]  == '+') {
//                 mul = 0;
//                 ad++;
//             } else if (map[j][i+j] == '*') {
//                 mul++;
//                 ad = 0;
//             }
//             if (ad == 5 || mul == 5) {
//                 cout << "Yes" << endl;
//                 return 0;
//             }
//         }
//         ad = 0;
//         mul = 0;

//         for(int j=0;j<20;j++)
//         {
//             if(i-j<0) break;

//             if (map[j][i-j] == '.') {
//                 ad = 0;
//                 mul = 0;
//                 continue;
//             } else if (map[j][i-j]  == '+') {
//                 mul = 0;
//                 ad++;
//             } else if (map[j][i-j] == '*') {
//                 mul++;
//                 ad = 0;
//             }
//             if (ad == 5 || mul == 5) {
//                 cout << "Yes" << endl;
//                 return 0;
//             }
//         }
//         ad = 0;
//         mul = 0;

//         for(int j=0;j<20;j++)
//         {
//             if(i+j>=20) break;

//             if (map[i+j][j] == '.') {
//                 ad = 0;
//                 mul = 0;
//                 continue;
//             } else if (map[i+j][j]   == '+') {
//                 mul = 0;
//                 ad++;
//             } else if (map[i+j][j]  == '*') {
//                 mul++;
//                 ad = 0;
//             }
//             if (ad == 5 || mul == 5) {
//                 cout << "Yes" << endl;
//                 return 0;
//             }
//         }
//         ad = 0;
//         mul = 0;

//         for(int j=0;j<20;j++)
//         {
//             if(i-j<0) break;

//             if (map[i-j][j] == '.') {
//                 ad = 0;
//                 mul = 0;
//                 continue;
//             } else if (map[i-j][j]  == '+') {
//                 mul = 0;
//                 ad++;
//             } else if (map[i-j][j]  == '*') {
//                 mul++;
//                 ad = 0;
//             }
//             if (ad == 5 || mul == 5) {
//                 cout << "Yes" << endl;
//                 return 0;
//             }
//         }
//         ad = 0;
//         mul = 0;

//     }

//     cout<<"No"<<endl;
//     return 0;
// }

// int main() {
//     vector<vector<char>> map(20, vector<char>(20));

//     while (cin >> map[0][0])
//     {
//     for (int i = 0; i < 20; i++) {
//         for (int j = 0; j < 20; j++) {
//             if(i==0&&j==0) continue;
//             cin >> map[i][j];
//         }
//     }
//     solve(map);

//     }

// }
// // 64 位输出请用 printf("%lld")

#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

map<int, int> pri = {{'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}};

int main()
{
    int n;
    while (cin >> n)
    { // 注意 while 处理多个 case
        stack<int> s;
        int ans = 0;
        while (n--)
        {
            string temp;
            cin >> temp;
            if (temp == "+" || temp == "-" || temp == "*" || temp == "/")
            {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();

                switch (temp[0])
                {
                case '+':
                    s.push(left + right);
                    break;
                case '-':
                    s.push(left - right);
                    break;
                case '*':
                    s.push(left * right);
                    break;
                case '/':
                    s.push(left / right);
                    break;
                }
            }
            else
            {
                s.push(atoi(temp.c_str()));
            }
            cout<<s.top()<<endl;
        }
    }
}
// 64 位输出请用 printf("%lld")