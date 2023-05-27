// // 本题为考试单行多行输入输出规范示例，无需提交，不计分。
// #include <iostream>
// #include <vector>
// using namespace std;
// int main() {
//     int a;
//     while(cin >> a)// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
//     {
//         vector<int> v={1,0,0};
//         for(int i=1;i<a;i++)
//         {
//             int temp = v[2]+v[1];
//             v[2]+=v[1];
//             v[1]=v[0];
//             v[0]=temp;
//         }
//         cout<<v[0]+v[1]+v[2]<<endl;
        
//     }
// }


// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>
using namespace std;

bool Isqu(char a, char b)
{
    if( a <= 'Z' && a>='A')
    a  = (a - 'A' + 'a');
    if( b <= 'Z' && b>='A')
    b  = (b - 'A' + 'a');
    return a==b;
}


bool Re(const string& a,const string&  b,int i,int j)
{    
    if(i == a.size() && j ==b.size())
    {
        return true;
    }
    if(i == a.size() || j ==b.size())
    {
        return false;
    }
    
    if(a[i]=='?')
    {
        if( !(isdigit(b[j]) || isalpha(b[j])))
           return false;
        return Re(a,b,i+1,j+1);
    }
    
    if(a[i]=='*')
    {
        while(i<a.size() && a[i+1]=='*')
            i++;
        
        if( !(isdigit(b[j]) || isalpha(b[j])))
           return Re(a,b,i+1,j);
        return Re(a,b,i+1,j+1)|| Re(a,b,i,j+1) ||Re(a,b,i+1,j);
    }
    
    if(Isqu(a[i],b[j]))
    {
        return Re(a,b,i+1,j+1);
    }

        return false;

    
    
}

int main() {
    string  a,b;
    while(cin >> a>>b)// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
    {
        if(Re(a,b,0,0))
        {
            cout<<"true"<<endl;
        }   
        else
        {
            cout<<"false"<<endl;
        }
    }
}