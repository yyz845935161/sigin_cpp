#include <iostream>
#include <vector>
using namespace std;
// int main()
// {
//     int pos = -1;

//     vector<int> v={1,2,3,4,5,6};
//     while(v.size()>pos++)
//     {
//         cout<<"进入循环了"<<endl;
//     }
//     cout<<"没进循环"<<endl;
//     return 0;
// }

class Person
{
public:
    virtual void BuyTicket() { cout << "买票-全价" << endl; }
};
class Student : public Person
{
public:
    virtual void BuyTicket() { cout << "买票-半价" << endl; }
};

void Func(Person &p)

{
    p.BuyTicket();
}
int main()
{
    Person ps;
    Student st;
    Func(ps);
    Func(st);
    return 0;
}
