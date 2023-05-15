#include <iostream>
#include <vector>
using namespace std;
#include <iostream>
int main() {
    int w,h;
    cin>>w>>h;
    vector<int> v;
    v.resize(w, 0);
    vector<vector<int>>  vv;
    for (int i=0; i<h; i++) {
        vv.push_back(v);
    }

    int ans=0;
    for (int i=0;i<h; i++) {
        
        for(int j=0;j<w;j++)
        {
            if(vv[i][j]==0) 
            {vv[i][j]=1;
            ans++;
            if(i+2 < h)vv[i+2][j] =-1;
            if(j+2 < w)vv[i][j+2] = -1;
            } 
        }
    }
    cout<<ans;


    
    
}
// 64 位输出请用 printf("%lld")


class Solution {
public:
    
    bool isNum(const char& a)
    {
        if(a<='9' && a>='0')return true;
        else
            return false;
    }
    
    
    int StrToInt(string str) {
        int s_size = str.size();
        int n=1;
        int ans=0;
        for(int i=0;i<s_size;i++)
        {
            if(isNum(str[s_size-i-1]))
            {
                ans+=n*(str[s_size-i-1]-'0');
                n*=10;
            }
            else
            {
                if(i==s_size-1 && (str[s_size-i-1]=='-' || str[s_size-i-1] =='+'))
                {
                    if(str[s_size-i-1]=='-')
                        ans= -ans;
                }
                else return 0;
            }
                
        }
        return ans;
    }
};