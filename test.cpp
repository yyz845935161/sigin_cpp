#include<iostream>
using namespace std;



void bigOrSmall()
{
    int i = 1;
    char *p = (char*)&i;
    if(*p == 1)
    {
        cout<<"小端"<<endl;
    }
    else
    {
        cout<<"大端"<<endl;
    }


}


int main()
{

    bigOrSmall();
    return 0;
    
}