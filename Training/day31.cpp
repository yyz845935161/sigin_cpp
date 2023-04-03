// write your code here cpp
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool is_su(int n)
{
    if (n == 2)
        return true;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void inf_in(int n, vector<int> &v)
{
    while (n > 1)
    {
        for (int i = 2; i <= n; i++)
        {
            if (!is_su(i) && i!=n)
                continue;

            if (n % i == 0)
            {
                while (n % i == 0)
                {
                    v.push_back(i);
                    n /= i;
                }
            }
        }
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> v;
        if (is_su(n))
        {
            cout << n << " = " << 1 << "*" << n << endl;
        }
        else
        {
            inf_in(n, v);
            cout << n << " =";
            for (int i = 0; i < v.size(); i++)
            {
                if (i == v.size() - 1)
                    cout << " " << v[i];
                else
                    cout << " " << v[i] << " *";
            }
            cout << endl;
        }
    }
    return 0;
}


// write your code here
// #include<iostream>
// #include<stdio.h>
// using namespace std;

// bool is_run(int n)
// {
//     if((n%400==0)||(n%4==0 && n%100!=0))
//     {
//         return true;
//     }
//     return false;
// }

// int month_day[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

// void MarDingMemeory(int year,int month,int num,int week)
// {
//     int run = 0;
//     for(int i=1;i<year;i++)
//     {
//         if(is_run(i))run++;
//     }
    
//     int day  =  (year-1)*365 +run ;
    
//     for(int i=1;i<month;i++)
//     {
//         day+=month_day[i];
//     }
    
//     if(month>2 && is_run(year)) day++;
    
//     int cur_week = day%7;
        
//     int count=0;
//     day=0;
//     for(int i=1;i<=month_day[month];i++)
//     {
//         if((i+cur_week) %7 == week) 
//         {count++;
//          day=i;
//         }
//         if(count==num) 
//         {
//           break;  
//          }
//     }
    
//     printf("%d-%02d-%02d\n",year,month,day);
    
    
    
// }


// int main()
// {
//     int y;
//     while(cin>>y)
//     {
//         printf("%d-%02d-%02d\n",y,1,1);
//         MarDingMemeory(y,1,3,1);
//         MarDingMemeory(y,2,3,1);
//         MarDingMemeory(y,5,-1,1);
//         printf("%d-%02d-%02d\n",y,7,4);
//         MarDingMemeory(y,9,1,1);
//         MarDingMemeory(y,11,4,4);
//         printf("%d-%02d-%02d\n\n",y,12,25);
        
//     }
// }