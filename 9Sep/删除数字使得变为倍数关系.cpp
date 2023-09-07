#include <iostream>
#include <vector>

using namespace std;

int countDeletionCases(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // 初始情况，不删除任何元素

    for (int i = 1; i <= n; ++i) {
        int divisibleCount = 0; // 计算当前元素能够整除的元素数量

        for (int j = i - 1; j >= 0; --j) {
            if (arr[i - 1] % arr[j] == 0 || arr[j] % arr[i - 1] == 0) {
                divisibleCount++;
                dp[i] += dp[j];
            }
        }

        // 单独考虑不删除当前元素的情况
        dp[i]++;

        // 如果删除的元素数量超过了 k，则只保留 k 个删除情况
        if (divisibleCount > k) {
            dp[i] -= dp[i - divisibleCount];
        }
    }

    return dp[n] - 1; // 减去初始情况
}

int main() {
    int n, k;
    cout << "输入数组大小 n：";
    cin >> n;
    vector<int> arr(n);
    cout << "输入数组元素：" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "输入要删除的元素数量 k：";
    cin >> k;

    int result = countDeletionCases(arr, k);
    cout << "删除情况数目：" << result << endl;

    return 0;
}