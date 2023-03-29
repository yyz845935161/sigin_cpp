#include <iostream>
using namespace std;
#include <string>
#include<stdio.h>
// bool isAr(char a)
// {
//     if(a <= 'z' && a >= 'a' || a <= 'Z' && a >= 'A' )
//     return true;
//     else return false;
// }
// int main() {
//     string s;
//     getline(cin,s);
//     string ans;
//     int begin=0;
//     int len=0;
//     int i = 0;
//     while(i< s.size()) {
//         if(isAr(s[i]))
//         {
//             i++;
//         }

//         else
//          {
//             begin = i;
//             while(i< s.size() && !isAr(s[i]))
//             {
//                 i++;
//             }
//             if(i - begin >len)
//             {
//                 len = i-begin;
//                 string temp(s.begin()+begin,s.begin()+i);
//                 ans = temp;
//             }

//          }

//     }
//     cout<<ans.c_str()<<endl;
//     return 0;
// }
// 64 位输出请用 printf("%lld")

void test01()
{
    struct S1
    {
        char c1;
        int i;
        char c2;
    };
    printf("%d\n", sizeof(struct S1));
    // 练习2
    struct S2
    {
        char c1;
        char c2;
        int i;
    };
    printf("%d\n", sizeof(struct S2));
    // 练习3
    struct S3
    {
        double d;
        char c;
        int i;
    };
    printf("%d\n", sizeof(struct S3));
    // 练习4-结构体嵌套问题
    struct S4
    {
        char c1;
        struct S3 s3;
        double d;
    };
    printf("%d\n", sizeof(struct S4));
}


void test02()
{
    class S1
    {
        char c1;
        int i;
        char c2;
    };
    printf("%d\n", sizeof( S1));
    // 练习2
    class S2
    {
        char c1;
        char c2;
        int i;
    };
    printf("%d\n", sizeof( S2));
    // 练习3
    class S3
    {
        double d;
        char c;
        int i;
    };
    printf("%d\n", sizeof( S3));
    // 练习4-结构体嵌套问题
    class S4
    {
        char c1;
        struct S3 s3;
        double d;
    };
    printf("%d\n", sizeof( S4));
}

int main()
{
         test01();
          test02();
    return 0;
}