#include <iostream>
#include <string>
using namespace std;

int MaxY(const int& a,const int& b)
{
    int min = a>b?b:a;
    int max = 1;
    for(int i=1;i<=min;i++)
    {
        if(a%i==0 && b%i==0) max=i;
    }
//     cout<<" "<<max<<" ";
    return max;
}


int main()
{
    int n,a;
    
    while(cin>>n>>a)
    {
    
    for(int i=0;i<n;i++)
    {
        int temp;
        cin>>temp;
        if(temp > a)
        {
            a+=MaxY(a,temp);
        }
        else
             a+=temp;
    }
    cout<<a<<endl;;
    }
    
    return 0;
}



#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int a[256] ={0};
    cin>>s;
    
    for(auto e:s)
    {
        a[e]+=1;
    }
    
    for(auto e:s)
    {
        if(a[e]==1) 
        {
            cout<<e;
            return 0;
        }
    }
    cout<<-1;
    

    
    return 0;
}