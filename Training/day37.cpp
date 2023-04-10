#include <iostream>
using namespace std;
#include <string>
#include <set>
int main() {
    int a;

    while (cin >> a) { // 注意 while 处理多个 case
        set<string> s;
        int max = 0;
        for (int i = 0; i < a; i++) {
            string temp, l, r;
            cin >> l >> r;
            // getline(cin, temp);
            // temp = "A connect";
            // l.insert(l.end(),temp.begin(), temp.begin()+temp.find(' '));
            if (r == "connect") {
                s.insert(l);
                if (s.size() > max) max = s.size();
            } else if (r == "disconnect") s.erase(l);

        }
        cout << max<<endl;;
    }
}
// 64 位输出请用 printf("%lld")


#include <iostream>
using namespace std;
#include <map>

int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        map<string,int> m;
        for (int i = 0; i < n; i++) {
            string temp;
            cin>>temp;
            // m.insert(make_pair(temp,0));
            m[temp]=0;
        }

        for(auto& e:m){
            for(auto& d:m){
                if(e!=d && d.first.find(e.first)!=-1)
                {
                    e.second=-1;
                    break;
                }
            }
        }

        for(auto e:m)
        {
            if(e.second !=-1) cout<<"mkdir -p "<<e.first<<endl;
        }
        cout<<endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")