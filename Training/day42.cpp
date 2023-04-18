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

// #include <iostream>
// using namespace std;
// #include <vector>

// int ans = INT16_MAX;

// vector<string> map(10);

// void find_path(int i, int j, int temp) {
//     temp++;
//     map[i][j] = '#';
//     if (i == 9 && j == 8) {
//         if (temp < ans)
//             ans = temp;
//     }

//     if (i + 1 < 10 && map[i + 1][j] == '.')
//         find_path(i + 1, j, temp);
//     if (j + 1 < 10 && map[i ][j + 1] == '.')
//         find_path(i, j + 1, temp);
//     if (i - 1 >= 0 && map[i - 1][j] == '.')
//         find_path(i - 1, j, temp);
//     if (j - 1 >= 0 && map[i][j - 1] == '.')
//         find_path(i, j - 1, temp);
//     // map[i][j] = '.';

// }

// int main() {
//     while (cin >> map[0]) {
//         // 注意 while 处理多个 case
//         int temp;
//         ans = INT16_MAX;
//         // cout << ans << endl;
//         for (int i = 1; i < 10; i++) {
//                     cin >> map[i];
//         }

//         find_path( 0, 1, 1);
//         cout << ans-2 << endl;
//     }
// }
// 64 位输出请用 printf("%lld")


#include <iostream>
using namespace std;
#include <vector>
#include<queue>
struct Position
{
    int x;
    int y;
    int level;
};


int bfs(vector<string>& map,int m,int n)
{
    int direct[4][2] = {{1,0},{0,1},{0,-1},{-1,0}};
    queue<Position> q;
    Position start{0,1,0}, out{9,8,0};
    q.push(start);
    

    vector<vector<bool>> flag(m,vector<bool>(n,false));
    while(!q.empty())
    {
        Position cur = q.front();
        // 遍历该位置，
        flag[cur.x][cur.y] = true;


        Position next;
        for(int i=0;i<4;++i)
        {
            next.x = cur.x + direct[i][0];
            next.y = cur.y + direct[i][1];
        }
    }


}


int main() {
    vector<string> map(10);
    while (cin >> map[0]) {
        for (int i = 1; i < 10; i++) {
                    cin >> map[i];
        }
        cout<< bfs(map,10,10)<<endl;


    }
}
