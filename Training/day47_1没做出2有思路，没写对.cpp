// #include <iostream>
// #include <vector>
// #include <math.h>
// #include <algorithm>
// using namespace std;

// int getMax(vector<int> &v, int n, int k, int d)
// {
//     vector<vector<long long>> vMax(n + 1, vector<long long>(k + 1, 0));
//     vector<vector<long long>> vMin(n + 1, vector<long long>(k + 1, 0));
//     long long ret = 0;

//     // 初始状态
//     for (int i = 1; i <= n; ++i)
//     {
//         vMax[i][1] = vMin[i][1] = v[i - 1];
//     }

//     for (int i = 1; i <= n; ++i)
//     {
//         for (int j = 2; j <= k; ++j)
//         {
//             // 选择的范围 i-d  i-1
//             for (int m = i - 1; m >= max(i - d, 1); --m)
//             {
//                 vMax[i][j] = max(vMax[i][j], max(vMax[m][j - 1] * v[i - 1], vMin[m][j - 1] * v[i - 1]));
//                 vMin[i][j] = min(vMin[i][j], min(vMax[m][j - 1] * v[i - 1], vMin[m][j - 1] * v[i - 1]));
//             }
//         }
//         // 更新最大值
//         ret = max(ret, vMax[i][k]);
//     }
//     return ret;
// }

// int main()
// {
//     int n, k, d;
//     cin >> n;
//     vector<int> v(n, 0);
//     for (int i = 0; i < n; ++i)
//         cin >> v[i];
//     cin >> k;
//     cin >> d;
//     cout << getMax(v, n, k, d);
//     return 0;
// }

// // int main()
// // {
// //     int n, k, d;
// //     cin >> n;
// //     vector<int> v(n);
// //     for (int i = 0; i < n; i++)
// //     {
// //         cin >> v[i];
// //     }
// //     cin >> k >> d;
// //     cout << getMax(v, n, k, d);
// // }

// // int main() {
// //     int n;
// //     int k, d;
// //     // vector<long long> ans(n);
// //     while (cin >> n) { // 注意 while 处理多个 case
// //         vector<long long > ai(n);
// //         for (int i = 0; i < n; i++) {
// //             cin >> ai[i];
// //         }
// //         cin >> k >> d;

// //         long long  ans = INT64_MIN;
// //         vector<vector<long long>>  vMax(k, vector<long long>(n));
// //         vector<vector<long long>>  vMin(k, vector<long long>(n));

// //         vMin[0][0] = ai[0];
// //         vMax[0][0] = ai[0];
// //         for (int i = 1; i < n; i++) {
// //             vMin[0][i] = min(vMin[0][i - 1], ai[i]);
// //             vMax[0][i] = max(vMax[0][i - 1], ai[i]);
// //         }

// //         for (int i = 1; i < k; i++) {
// //             for (int j = i; j < n; j++) {
// //                 int temp_min = vMin[i - 1][j - 1] * ai[j];
// //                 int temp_max = vMax[i - 1][j - 1] * ai[j];
// //                 for (int l = 0; l < d; l++) {
// //                     if (j - 1 - l >= 0 && vMin[i - 1][j - 1 - l]*ai[j] < temp_min)
// //                         temp_min = vMin[i - 1][j - 1 - l] * ai[j];
// //                     if (j - 1 - l >= 0 && vMin[i - 1][j - 1 - l]*ai[j] > temp_max)
// //                         temp_max = vMin[i - 1][j - 1 - l] * ai[j];

// //                     if(j - 1 - l >= 0 && i==k-1 && vMin[i - 1][j - 1 - l] * ai[j] >ans ) ans = vMin[i - 1][j - 1 - l] * ai[j];
// //                     if(j - 1 - l >= 0 && i==k-1 && vMax[i - 1][j - 1 - l] * ai[j] >ans ) ans = vMax[i - 1][j - 1 - l] * ai[j];

// //                 }
// //                 vMin[i][j] = temp_min;
// //                 vMax[i][j] =temp_max;
// //             }
// //         }
// //         if(n==1) ans = ai[0];
// //         cout<<ans<<endl;

// //     }
// // }
// // // 64 位输出请用 printf("%lld")

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Less
{
    bool operator()(const vector<int> &a, const vector<int> &b)
    {
        if(a[1]!=b[1])
        return a[1] <= b[1];
        else
        return a[2] <= b[2];
    }
};

int main()
{
    int n;
    while (cin >> n)
    { // 注意 while 处理多个 case
        vector<vector<int>> v(n + 1, vector<int>(3));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 3; ++j)
            {
                cin >> v[i][j];
            }
        }
        sort(v.begin(), v.end(), Less());
        // vector<int> ans(n+1,1);
        // int max_ans=0;
        // for(int i=1;i<=n;i++)
        // {
        //     int temp_max=0;
        //     for(int j=i-1;j>=1;j--)
        //     {
        //         if(v[i][2]>=v[j][2])
        //         {
        //             temp_max = max(temp_max,ans[j]);
        //         }
        //     }
        //     ans[i] = temp_max+1;
        //     max_ans = max(max_ans,ans[i]);
        // }

        vector<int> dp(n, 1);
        int max = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] + 1 > dp[i] && v[i][2] >= v[j][2])
                {
                    dp[i] = dp[j] + 1;
                }
            }
            if (dp[i] > max)
                max = dp[i];
        }
        cout << max << endl;
    }
    return 0;
}