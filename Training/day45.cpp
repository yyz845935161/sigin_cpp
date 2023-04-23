// #include <iostream>
// #include <unordered_map>
// using namespace std;

// void find_ball(unordered_map<char,int>& A,string b)
// {
//     for(auto e:b)
//         {
//             if(A.find(e)==A.end())
//             {
//                 cout<<"No"<<endl;
//                 return;
//             }
//             else
//             {
//                 A[e]--;
//                 if(A[e]<0)
//                 {
//                     cout<<"No"<<endl;
//                     return;
//                 }
//             }
//         }

//         cout<<"Yes"<<endl;
// }

// int main() {
//     string a,b;
//     while (cin >> a >>b) { // 注意 while 处理多个 case
//         unordered_map<char,int> A,B;
//         for(auto e:a)
//         {
//             A[e]++;
//         }
//         find_ball(A,b);

//     }
//     return 0;
// }
// // 64 位输出请用 printf("%lld")


#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;

bool is_bro( string a, string b)
{
    if(a.size()!=b.size() || a==b)
    {
        return false;
    }
    unordered_map<char,int> m;
    for(auto& e:a)
    {
        m[e]++;
    }
    for(auto& e:b)
    {
        if(m.find(e)==m.end())
        {
            return false;
        }
        else 
        {
            m[e]--;
            if(m[e]<0)
            {
                return false;
            }
        }
    }
    return true;
    // sort(a.begin(),a.end());
    // sort(b.begin(),b.end());
    // if(a==b)
    // return true;
    // else
    // return false;
}



int main() {
    int n;
    while (cin >> n) { // 注意 while 处理多个 case
        vector<string> v(n);
        int k;
        string x;
        multiset<string> bro_s;
        while (n--) {
            cin>>v[n];
        }
        cin>>x>>k;
        int temp=k;
        int count=0;
        for(int i=0;i<v.size();i++)
        {   
            if(is_bro(v[i],x))
            {
                bro_s.insert(v[i]);
            }
        }
        cout<<bro_s.size()<<endl;
        auto it =  bro_s.begin();
        while (--k) {
            it++;
        }
        // cout<<bro_s.size()<<k<<endl;
        if(bro_s.size() >= temp) 
        cout<<*it<<endl;
        
    }
    return 0;
}
// 64 位输出请用 printf("%lld")