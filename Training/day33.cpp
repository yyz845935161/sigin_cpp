#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        int i = 0;
        int count = 0;
        for (; i < a.size();) {
            if (a[i] == b[0]) {
                int j = 1;
                while (j < b.size() && i + j < a.size() && a[i + j] == b[j]) {
                    j++;
                }
                if (j == b.size()) {
                    count++;
                    i += j;
                } else i++;
            } else i++;
        }
        cout << count<<endl;;
    }
}
#include <iostream>
using namespace std;

int main() {
    // int a, b;
    string a,b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        int i=0;
        while(a.find(b)!= string::npos)
        {
            i++;

            a.erase(a.find(b),b.size());
        }
        cout<<i<<endl;;
    }
}
// 64 位输出请用 printf("%lld")


#include <iostream>
using namespace std;

int main() {
    int day[80] = {0};
    long long  guke[3] = {1, 0, 0};
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        long long  count = 0;
        for (int i = 2; i <= b; i++) {
            int temp = guke[1];
            guke[1] += guke[0];
            guke[0] = temp;
            if (i >= a && i <= b) {
                count = count + guke[0] + guke[1];
            }
        }
        if (a == 1) count++;
        printf("%lld\n", count);
        guke[0] = 1;
        guke[1] = 0;
    }
}
// 64 位输出请用 printf("%lld")