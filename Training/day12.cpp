#include <any>
#include <iostream>
#include <cstdio>

using namespace std;


class BinInsert {
  public:
    int binInsert(int n, int m, int j, int i) {
        // write code here
        while (j--) {
            cout << j << endl;
            m = (m << 1);
        }
        // cout << (m | n) << endl;
        return (m | n);
    }
};


#include <cmath>
#include <complex>
#include <iostream>
using namespace std;

bool is_su(int n) {
    if (n < 3) return true;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0 ) return false;
    }
    return true;
}


int main() {
    int n;
    while (cin >> n ) { // 注意 while 处理多个 case
        int a, b;
        int max = n;
        for (int i = 2; i <= n / 2; i++) {
            if (is_su(i) && is_su(n-i)) {
                a = i;
                b = n - i;
                // if (max > abs(i - (n - i))) {
                    
                // }
            }
        }
        cout<<a<<endl<<b;
    }
}
// 64 位输出请用 printf("%lld")