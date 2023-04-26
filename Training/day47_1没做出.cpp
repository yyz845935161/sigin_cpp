#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int getMax(vector<int> &v, int n, int k, int d)
{
    vector<vector<long long>> vMax(n + 1, vector<long long>(k + 1, 0));
    vector<vector<long long>> vMin(n + 1, vector<long long>(k + 1, 0));
    long long ret = 0;

    // 初始状态
    for (int i = 1; i <= n; ++i)
    {
        vMax[i][1] = vMin[i][1] = v[i - 1];
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k; j++)
        {
            // 选择的范围 i-d  i-1
            for (int m = i - 1; m >= max(i - d, 1); --m)
            {
                vMax[i][j] = max(vMax[i][j], max(vMax[m][j - 1] * v[i - 1], vMin[m][j - 1] * v[i - 1]));
                vMin[i][j] = min(vMin[i][j], min(vMax[m][j - 1] * v[i - 1], vMin[m][j - 1] * v[i - 1]));
            }
        }
        // 更新最大值
        ret = max(ret, vMax[i][k]);
    }
    return ret;
}

int main()
{
    int n, k, d;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cin >> k;
    cin >> d;
    cout << getMax(v, n, k, d);
    return 0;
}

// int main()
// {
//     int n, k, d;
//     cin >> n;
//     vector<int> v(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> v[i];
//     }
//     cin >> k >> d;
//     cout << getMax(v, n, k, d);
// }

// int main() {
//     int n;
//     int k, d;
//     // vector<long long> ans(n);
//     while (cin >> n) { // 注意 while 处理多个 case
//         vector<long long > ai(n);
//         for (int i = 0; i < n; i++) {
//             cin >> ai[i];
//         }
//         cin >> k >> d;

//         long long  ans = INT64_MIN;
//         vector<vector<long long>>  vMax(k, vector<long long>(n));
//         vector<vector<long long>>  vMin(k, vector<long long>(n));

//         vMin[0][0] = ai[0];
//         vMax[0][0] = ai[0];
//         for (int i = 1; i < n; i++) {
//             vMin[0][i] = min(vMin[0][i - 1], ai[i]);
//             vMax[0][i] = max(vMax[0][i - 1], ai[i]);
//         }

//         for (int i = 1; i < k; i++) {
//             for (int j = i; j < n; j++) {
//                 int temp_min = vMin[i - 1][j - 1] * ai[j];
//                 int temp_max = vMax[i - 1][j - 1] * ai[j];
//                 for (int l = 0; l < d; l++) {
//                     if (j - 1 - l >= 0 && vMin[i - 1][j - 1 - l]*ai[j] < temp_min)
//                         temp_min = vMin[i - 1][j - 1 - l] * ai[j];
//                     if (j - 1 - l >= 0 && vMin[i - 1][j - 1 - l]*ai[j] > temp_max)
//                         temp_max = vMin[i - 1][j - 1 - l] * ai[j];

//                     if(j - 1 - l >= 0 && i==k-1 && vMin[i - 1][j - 1 - l] * ai[j] >ans ) ans = vMin[i - 1][j - 1 - l] * ai[j];
//                     if(j - 1 - l >= 0 && i==k-1 && vMax[i - 1][j - 1 - l] * ai[j] >ans ) ans = vMax[i - 1][j - 1 - l] * ai[j];

//                 }
//                 vMin[i][j] = temp_min;
//                 vMax[i][j] =temp_max;
//             }
//         }
//         if(n==1) ans = ai[0];
//         cout<<ans<<endl;

//     }
// }
// // 64 位输出请用 printf("%lld")