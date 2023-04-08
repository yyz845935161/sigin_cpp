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
