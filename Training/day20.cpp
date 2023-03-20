// 本题为考试多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    cout<<s;
    return 0;
}

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1;
    string s2;
    cin>>s1>>s2;
    int ans=0;
    for(int i=0;i<s1.size();i++)
    {
        for(int j=0;j<s2.size();j++)
        {
            if(s1[i]==s2[j])
            {
                int tempi=i;
                int tempj=j;
                int cont=1;
                while(tempi+1<i<s1.size() && tempj+1<s2.size() && s1[tempi+1]==s2[tempj+1])
                {
                    tempi++;
                    tempj++;
                    cont++;
                }
                if(cont > ans) ans=cont;
            }
        }
    }
    cout<<ans;
    
    
    return 0;
}
