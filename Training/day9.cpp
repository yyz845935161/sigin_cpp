class UnusualAdd {
public:
    int addAB(int A, int B) {
        
        while (A&B) {
            int c = (A&B)<<1;
            B = A^B;
            A = c;
        }
        return A^B;
    }
};

#include <iostream>
#include <vector>
using namespace std;




int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        vector<vector<int>> v(a + 1, vector<int>(b + 1, 0));

        for (int i = 0; i < a + 1; i++) {
            for (int j = 0; j < b + 1; j++) {
                v[0][0] = 1;
                int tempi = 0;
                int tempj = 0;
                if (j - 1 >= 0) tempj = v[i][j - 1];
                if (i - 1 >= 0) tempi = v[i - 1][j];
                v[i][j] = tempi + tempj;
            }

        }
        cout << v[a][b] << endl;
    }
}
// 64 位输出请用 printf("%lld")