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


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> v;
    cin>>n;
    v.reserve(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int ans=v[0];
    int be = ans;
    for(int i=1;i<n;i++)
    {
        if(be+v[i]>v[i])
        {
            be+=v[i];
        }
        else 
        {
            be=v[i];
        }
        if(be>ans) ans=be;
    }
    cout<<ans;

    return 0;
}
// 64 位输出请用 printf("%lld")