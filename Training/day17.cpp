// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a;
    while(cin >> a )// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
    {
        vector<vector<int>> vv;
        vv.push_back({0,0,1,0,0});
        for(int i=1;i<a;i++)
        {
            vector<int> v((i+2)*2+1,0);
            for(int j=2;j<(i+2)*2+1-2;j++)
            {
                v[j]=vv[0][j-1] + vv[0][j-2] + vv[0][j];
            }
            vv.pop_back();
            vv.push_back(v);
        }
        
        for(int i=2;i<vv[0].size();i++)
        {
//             cout<<vv[0][i]<<' ';
            if(vv[0][i]%2==0 && vv[0][i]!=0) 
            {
                cout<<i-1<<endl;
                break;
            }
            if(i==vv[0].size()-1) 
            {
                cout<<-1<<endl;
                break;
            }
        }
        return 0;
        
    }
}

// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
using namespace std;
int main() {
    string a;
    char c;
    while(getline(cin, a))// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
    {    cin>>c;
     getchar();
     char c1 = c;
        if(isalpha(c))
        {
            if(c <= 'z' && c>= 'a')
            {
                c1 = 'A'+c-'a';
            }
            else
            {
                c1 = 'a'+c-'A';
            }
        }
    
     
        int ans=0;
        for(auto& e:a)
        {
            if(e == c || e==c1)
            {
                ans++;
            }

        }
     cout<<ans<<endl;
    }
}