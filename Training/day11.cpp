#include<stack>

class LCA {
public:
    int getLCA(int a, int b) {
        // write code here
        stack<int> path_a;
        stack<int> path_b;
        int comm;
        while(a)
        {
            path_a.push(a);
            a/=2;
        }
        while(b)
        {
            path_b.push(b);
            b/=2;
        }

        while(!path_a.empty() && !path_b.empty())
        {
            if(path_a.top()==path_b
            .top())
            {
                comm = path_a.top();
                path_a.pop();
                path_b.pop();
            }
            else {
            break;
            }
        }

        return comm;
    }
};


#include <iostream>
using namespace std;

int main() {
    int a;
    int max = 0;
    int temp = 0;
    while (cin >> a) { // 注意 while 处理多个 case
        while (a) {
            if ((a & 1) == 1) {
                temp++;
            } else {
                temp = 0;
            }
            if (temp > max) {
                max = temp;
            }

            a = (a >> 1);
        }
        cout << max;
    }
}
// 64 位输出请用 printf("%lld")