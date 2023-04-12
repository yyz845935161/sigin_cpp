#include <iostream>
#include <string>
using namespace std;
#include <vector>

int main() {
    string a;
    vector<string> v;
    getline(cin, a);
    while (a.find(' ') != string::npos && !a.empty()) {
        if (a[0] == '"') {
            v.push_back(a.substr(1, a.find('"', 1)-1));
            if(a.find('"', 1) + 2<a.size())
            a = a.substr(a.find('"', 1) + 2, a.size());
            else
             a.clear();

        } else {
            v.push_back(a.substr(0, a.find(' ')));
            a = a.substr(a.find(' ') + 1, a.size());
        }

        // cout<<a<<endl;
    }
    if(!a.empty())
    v.push_back(a);

    cout << v.size() << endl;
    for (auto& e : v) {
        cout << e << endl;
    }

}
// 64 位输出请用 printf("%lld")