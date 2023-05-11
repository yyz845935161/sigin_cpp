#include <iostream>
using namespace std;
#include <string>

// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
using namespace std;

bool IsReBack(const string& s)
{
    int l=0,r=s.size()-1;
    while(l<r)
    {
        if(s[l]!=s[r]) return false;
        ++l,--r;
    }
    return true;
}


int main() {
    string s;
    string c;
    while(cin >> s >> c)
    {// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
        int ans=0;
        for(int i=0;i<=s.size();i++)
        {
            string temp=s;
            temp.insert(i, c);
            if(IsReBack(temp))ans++;
        }
    
    cout<<ans<<endl;
    }
    
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