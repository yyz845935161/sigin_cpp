#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string str;
    int ans=0;
    while(cin>>str)
    {
        
    for(auto e:str)
    {
        ans+= (int)(e-'0');
        if(ans>=10)
        {
            int temp1=ans/10;
            int temp2=ans%10;
            ans = temp1+temp2;
        }
        
        
    }
        
        cout<<ans<<endl;
        ans=0;
        }
    
}

// write your code here cpp// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a;
    while(cin >> a)// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
    {
        vector<int> v(a);
        int max=0;
        for(int i=0;i<a;i++)
        {
            cin>>v[i];
            if(v[i]>max)
            {
                max=v[i];
            }
        }
        vector<int> vv(max);
        vv[0]=1;
        vv[1]=2;
        for(int i=2;i<max;i++)
        {
          vv[i]=(vv[i-1]+vv[i-2])%10000;  
        }
        string ans;
        for(int i=0;i<a;i++)
        {
            printf("%04d",vv[v[i]-1]);
        }
        cout<<endl;
        
    }
    return 0;
}