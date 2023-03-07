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

// class Person
// {
// public:
//     virtual void BuyTicket() { cout << "买票-全价" << endl; }
// };
// class Student : public Person
// {
// public:
//     virtual void BuyTicket() { cout << "买票-半价" << endl; }
// };

// void Func(Person &p)

// {
//     p.BuyTicket();
// }
// int main()
// {
//     Person ps;
//     Student st;
//     Func(ps);
//     Func(st);
//     return 0;
// }


int main() {
    string s;
    string ans;
    getline(cin, s);
    signed int substri = s.rfind(" ");
    int last_index = s.size();
    while(substri)
    {
        for(int i=substri+1;i<last_index;i++){
            // cout<<s[i];
            ans+=s[i];
        }
        ans+=" ";
        string temp(s.begin(),s.begin()+substri);
        last_index =substri;
        substri = temp.rfind(" ");
        if(substri == -1)
        {
            break;;
        }
        
    }

    for(int i=substri+1;i<last_index;i++){
            ans+=s[i];
        }

    cout<<ans;
    return 0 ;
    
}


#include <iostream>
using namespace std;
#include <string>

bool isAr(char a)
{
    if(a <= 'z' && a >= 'a' || a <= 'Z' && a >= 'A' )
    return true;
    else return false;
}
int Alobort() {
    string s;
    getline(cin,s);
    string ans;
    int begin=0;
    int len=0;
    int i = 0;
    while(i< s.size()) {
        if(isAr(s[i]))
        {
            i++;
            continue;
        }

        else
         {
            begin = i;
            while(!isAr(s[i]))
            {
                i++;
            }
            if(i - begin >len)
            {
                len = i-begin;
            }
            string temp(s.begin()+begin,s.begin()+i);
            ans = temp;
         }
    
    }
    cout<<ans<<endl;
    return 0;
}