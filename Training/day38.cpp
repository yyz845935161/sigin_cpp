// #include <iostream>
// #include <vector>
// using namespace std;
// int m, n;
// int temp_ans = 0;
// int ans = 0;

// void count_black(int i, int j, vector<vector<char>>& vv) {
//     temp_ans++;
//     vv[i][j] = '#';
//     if ((i + 1 >= m || vv[i + 1][j] == '#') && (i - 1 < 0 || vv[i - 1][j] == '#') &&
//             (j + 1 >= n || vv[i][j + 1] == '#') && (j - 1 < 0 || vv[i][j - 1] == '#')) {
//         if (temp_ans > ans) {
//             ans = temp_ans;
//         }
//     }

//     if ((i + 1 < m && vv[i + 1][j] == '.'))
//         count_black(i + 1, j, vv);
//     if ((i - 1 >= 0 && vv[i - 1][j] == '.'))
//         count_black(i - 1, j, vv);
//     if ((j + 1 < n && vv[i ][j + 1] == '.'))
//         count_black(i, j + 1, vv);
//     if ((j - 1 >= 0 && vv[i][j - 1] == '.'))
//         count_black(i, j - 1, vv);

//     // vv[i][j] = '.';
// }

// int main() {

//     while (cin >> m >> n) {
//         // 注意 while 处理多个 case

//         temp_ans = 0;
//         ans = 0;
//         vector<vector<char>> vv(m, vector<char>(6));
//         int cur_i, cur_j;
//         for (int i = 0; i < m; i++) {
//             string temp;
//             cin >> temp;
//             for (int j = 0; j < n; j++) {
//                 vv[i][j] = temp[j];
//                 if (temp[j] == '@') {
//                     cur_i = i;
//                     cur_j = j;
//                 }
//             }
//         }

//         count_black(cur_i, cur_j, vv);
//         cout<<ans<<endl;
//     }
// }
// // 64 位输出请用 printf("%lld")


#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int m, n, k;
int path = 0;
int mo_path = 0;

void find_path(int i, int j, vector<vector<int>>& vv, bool is_mo) {
    if (i == n - 1 && j == m - 1) {
        path++;
        if (is_mo) mo_path++;
        return ;
    }

    if (vv[i][j] == 1) is_mo = true;

    if (i + 1 < n) find_path(i + 1, j, vv, is_mo);
    if (j + 1 < m) find_path(i, j + 1, vv, is_mo);
}



int main() {

    while (cin >> n >> m) {
        // 注意 while 处理多个 case
        path = 0;
mo_path = 0;
        vector<vector<int>> vv(n, vector<int>(m, 0));
        cin >> k;
        while (k--) {
            int tempi, tempj;
            cin >> tempi >> tempj;
            vv[tempi - 1][tempj - 1] = 1;
        }
        find_path(0, 0, vv, false);


        printf("%.2f\n", ((double)path - (double)mo_path) / (double)path);
    }
}
// 64 位输出请用 printf("%lld")
// 64 位输出请用 printf("%lld")



#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int m, n, k;
int path = 0;
int mo_path = 0;

void find_path(int i, int j, vector<vector<int>>& vv, bool is_mo) {
    if (i == n - 1 && j == m - 1) {
        path++;
        if (is_mo) mo_path++;
        return ;
    }

    if (vv[i][j] == 1) is_mo = true;

    if (i + 1 < n) find_path(i + 1, j, vv, is_mo);
    if (j + 1 < m) find_path(i, j + 1, vv, is_mo);
}



int main() {

    while (cin >> n >> m) {
        // 注意 while 处理多个 case
        vector<vector<double>> vv(n, vector<double>(m, 0));
        cin >> k;
        while (k--) {
            int tempi, tempj;
            cin >> tempi >> tempj;
            vv[tempi - 1][tempj - 1] = 1;
        }

        vv[0][0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i!=0 && j!=0 )
                {
                    double a=0.5,b=0.5;
                    if(i==n-1) a=1;
                    if(j==m-1) b=1;
                    
                    vv[i][j] = b*vv[i-1][j] + a*vv[i][j-1];
                }
            }
        }



        printf("%.2f", ((double)path - (double)mo_path) / (double)path);
    }
}
// 64 位输出请用 printf("%lld")