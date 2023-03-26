// class Bonus {
// public:
//     int depgetMost(vector<vector<int> > board,int i,int j)
//     {
//         if(i==5&&j==5)
//         {
//             return board[i][j];
//         }

//         if(i==5)
//         {
//             return depgetMost(board,i,j+1) + board[i][j];
//         }
//         if(j==5)
//         {
//             return depgetMost(board,i+1,j) + board[i][j];
//         }
//         else
//         {
//             return max(depgetMost(board,i+1,j) + board[i][j],depgetMost(board,i,j+1) + board[i][j]);
//         }
//     }

//     int getMost(vector<vector<int> > board) {
//         // write code here

//      return depgetMost(board,0,0);
//     }
// };

// #include <iostream>
// #include <vector>
// using namespace std;
// int ROW, COL;
// vector<vector<int>> maze;
// vector<vector<int>> path_tmp;  // 临时路劲
// vector<vector<int>> path_best; // 最佳路劲
// void MazeTrack(int i, int j)
// {

//     maze[i][j] = 1; // 代表（i,j）已经走过
//     path_tmp.push_back({i, j});
//     // 判断是否到达出口
//     if (i == ROW - 1 && j == COL - 1)
//     {
//         // 寻找最短路劲
//         if (path_best.empty() || path_best.size() > path_tmp.size())
//             path_best = path_tmp;
//     }
//     // 向右走
//     if (j + 1 < COL && maze[i][j + 1] == 0)
//         MazeTrack(i, j + 1);
//     // 向左走
//     if (j - 1 >= 0 && maze[i][j - 1] == 0)
//         MazeTrack(i, j - 1);
//     // 向上走
//     if (i - 1 >= 0 && maze[i - 1][j] == 0)
//         MazeTrack(i - 1, j);
//     // 向下走
//     if (i + 1 < ROW && maze[i + 1][j] == 0)
//         MazeTrack(i + 1, j);
//     maze[i][j] = 0; // 回溯 恢复路劲
//     path_tmp.pop_back();
// }
// int main()
// {
//     while (cin >> ROW >> COL)
//     {
//         maze = vector<vector<int>>(ROW, vector<int>(COL, 0)); // 开辟迷宫空间
//         path_tmp.clear();
//         path_best.clear();
//         // 首先输入迷宫
//         for (int i = 0; i < ROW; ++i)
//         {
//             for (int j = 0; j < COL; ++j)
//                 cin >> maze[i][j];
//         }
//         MazeTrack(0, 0); // 从起始点（0，0）开始走
//         // 输出路径
//         for (int i = 0; i < path_best.size(); ++i)
//         {
//             cout << "(" << path_best[i][0] << "," << path_best[i][1] << ")" << endl;
//         }
//     }
//     return 0;
// }

#include <iostream>
using namespace std;
#include <vector>

vector<vector<int>> path_temp;

void deepout(vector<vector<int>> &vv, int n, int m, int i, int j, vector<vector<int>> &ans, char bef)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
    {
        return;
    }
    if (vv[i][j] == 1)
    {
        return;
    }
    vv[i][j] = 1;
    path_temp.push_back({i, j});
    if (i == n - 1 && j == m - 1) // 寻找最佳路径
    {
        // 寻找最佳路径
        if (ans.empty() || ans.size() > path_temp.size())
            ans = path_temp;
    }

    // if (bef != 'd')
        deepout(vv, n, m, i + 1, j, ans, 'u');
    // if (bef != 'u')
        deepout(vv, n, m, i - 1, j, ans, 'd');
    // if (bef != 'r')
        deepout(vv, n, m, i, j + 1, ans, 'l');
    // if (bef != 'l')
        deepout(vv, n, m, i, j - 1, ans, 'r');

    vv[i][j] = 0; // 回溯
    path_temp.pop_back();
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        vector<vector<int>> vv;
        vector<int> v(m);
        vv.resize(n, v);
        vector<vector<int>> ans;

        path_temp.clear();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> vv[i][j];
            }
        }
        // for (auto& e:vv)
        // {
        //     for (auto a:e) {
        //         cout << a << ' ';
        //     }
        //     cout<<endl;
            
        // }
            // cout<<'-';
        deepout(vv, n, m, 0, 0, ans, 'r');

        for (int i = 0; i < ans.size(); i++)
        {

            cout << '(' << ans[i][0] << ',' << ans[i][1] << ')' << endl;
        }
    }
    return 0;
}