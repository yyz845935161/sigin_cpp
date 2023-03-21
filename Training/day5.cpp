#include <iostream>
using namespace std;
#include <string>

bool isReback(const string & s)
{


    auto l = s.begin();
    auto r = s.end()-1;
    while (l<r) {
        if(*l != *r) return false;
        l++;
        r--;
    }
    return true;
}

int main() {
    string s1,s2;
    int ans=0;
    cin>>s1>>s2;
    for (int i=0; i<=s1.size(); i++) {
        string temp = s1;
        temp.insert(i, s2);
        if(isReback(temp)) ans++;

    }
    cout<<ans;



    
}
// 64 位输出请用 printf("%lld")