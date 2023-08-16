#include<iostream>
using namespace std;

class A
{
public:
    virtual void func1()
    {
        cout<<"父类的func1"<<endl;
    }
    void func2()
    {
        cout<<*(long long*)this<<endl;
    }
};

class B:public A
{
public:
    virtual void func1()
    {
        cout<<"子类的func1"<<endl;
    }
    void func2()
    {
        cout<<*(long long*)this<<endl;
    }
};


int main()
{
    cout<<sizeof(long long)<<endl;

    A a;
    B b;
    A* aa = new B;
    aa->func1();
    aa->func2();
    a.func2();
    B b2;
    b.func2();
    b2.func2();



    return 0;
}