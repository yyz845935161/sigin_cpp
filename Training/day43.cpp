// #include <iostream>
// #include <vector>
// #include <queue>
// #include <unordered_set>
// #include <set>
// #include <unordered_map>
// #include <map>
// using namespace std;

// class A{

// public:
// static unordered_map<char, char> b;
// };

// unordered_map<char, char> A::b={{'A','1'}};
// // A::b.insert({'B','2'});
// // b['A'] = '2';




// //b['A'] = '2';
// int main()
// {
//     unordered_map<char, char> phoneMap;
//     A::b.insert({'B','2'});
//     phoneMap['A'] = '2';
//     phoneMap['B'] = '2';
//     phoneMap['C'] = '2';

//     phoneMap['D'] = '3';
//     phoneMap['E'] = '3';
//     phoneMap['F'] = '3';

//     phoneMap['G'] = '4';
//     phoneMap['H'] = '4';
//     phoneMap['I'] = '4';

//     phoneMap['J'] = '5';
//     phoneMap['K'] = '5';
//     phoneMap['L'] = '5';

//     phoneMap['M'] = '6';
//     phoneMap['N'] = '6';
//     phoneMap['O'] = '6';

//     phoneMap['P'] = '7';
//     phoneMap['Q'] = '7';
//     phoneMap['R'] = '7';
//     phoneMap['S'] = '7';

//     phoneMap['T'] = '8';
//     phoneMap['U'] = '8';
//     phoneMap['V'] = '8';

//     phoneMap['W'] = '9';
//     phoneMap['X'] = '9';
//     phoneMap['Y'] = '9';
//     phoneMap['Z'] = '9';
//     int n;
//     while (cin >> n)
//     {
//         set<string> ans;
//         unordered_set<string> s;
//         while (n--)
//         {
//             string temp;
//             cin >> temp;
//             string temp2;
//             for (auto &e : temp)
//             {
//                 if (e <= 'Z' && e >= 'A')
//                     temp2 += phoneMap[e];
//                 else if (e <= '9' && e >= '0')
//                     temp2 += e;
//             }
//             temp2.insert(3, "-");
//             if (s.find(temp2) == s.end())
//             {
//                 s.insert(temp2);
//                 ans.insert(temp2);
//             }
//         }
//         for (auto e : ans)
//         {
//             cout << e << endl;
//         }
//         cout << endl;
//     }
//     return 0;
// }


#include <iostream>
#include<set>
#include<vector>
using namespace std;
int a, b;

void find_merge(int i,set<vector<int>>& ans,vector<int> v,int sum)
{
    if(sum==b)
    {
        ans.insert(v);
        return;
    }
    if(i==a)
    {
        return;
    }
    
    else if(sum>b)
    {
        return;
    }
    


    for(int j=i;j<a;j++)
    {
        v.push_back(i+1);
        sum+=(i+1);
        find_merge(j,ans,v,sum);
        v.pop_back();
        sum-=(i-1);
    }

}

int main() {

    while (cin >> a >> b) { // 注意 while 处理多个 case
        set<vector<int>> ans;
        vector<int> v;
        find_merge(0,ans,v,0);

        for(auto& e:ans)
        {
            for(auto& i:e)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }

    }
    return 0;
}
// 64 位输出请用 printf("%lld")