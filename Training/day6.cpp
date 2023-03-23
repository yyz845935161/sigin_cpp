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