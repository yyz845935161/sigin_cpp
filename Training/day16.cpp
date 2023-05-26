// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include<math.h>
using namespace std;

bool IsCom(const int& n)
{
    int sum=1;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            sum+=i;
            sum+= (n/i);
        }
    }
    if(sum==n) return true;
    else return false;
}

int main() {
    int a;
    while(cin >> a)// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
    {
        int ans=0;
        for(int i=2;i<=a;i++)
        {
            if(IsCom(i)) ans++;
        }
        cout<<ans;
    }
    return 0;
}