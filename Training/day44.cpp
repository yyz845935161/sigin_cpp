// #include <iostream>
// #include <string>
// using namespace std;



// int main() {
//     string a;
//     while (cin >> a) { // 注意 while 处理多个 case
//         while (a.find('_')!=-1) {
//             int index = a.find('_');
//             a[index+1] = a[index+1] + 'A' - 'a';
//             //a.erase(index);
//             a.erase(index,1);
//             // string::iterator position = a.begin()+index;
//             // a.erase(position);
//         }
//         cout<<a<<endl;
//     }
//     return 0;
// }
// // 64 位输出请用 printf("%lld")

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string a ;
    while (getline(cin, a)) { // 注意 while 处理多个 case
        reverse(a.begin(), a.end());
        int b = 0;
        string temp;
        string ans;
        for (int i = 0; i < a.size(); i++) {
            
            if ((a[i] <= 'z' && a[i] >= 'a') || (a[i] <= 'Z' && a[i] >= 'A')) {
                temp += a[i];
            } else {
                if (temp.size() != 0) {
                    reverse(temp.begin(),  temp.end());
                    temp+=' ';
                    ans+=temp;
                    temp.clear();
                }
            }
        }

        if (temp.size() != 0) {
                    reverse(temp.begin(),  temp.end());
                    temp+=' ';
                    ans+=temp;
                }

        ans.erase(ans.size()-1,1);
        cout<<ans<<endl;;
        

    }
}
// 64 位输出请用 printf("%lld")