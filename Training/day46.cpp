// class Solution {
// public:
//     int MoreThanHalfNum_Solution(vector<int> numbers) {
//         // if(number,size()==0) return

//         int count=0,ans=numbers[0];
//         for(auto e:numbers)
//         {
//             if(e==ans)
//             {
//                 count++;
//             }
//             else
//             {
//                 count--;
//                 if(count<0)
//                 {ans=e;
//                 count=1;
//                 }
//             }
//         }
//         return ans;

        
//     }
// };



#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int main() {
    string a;
    unordered_map<string,int> m;
    queue<string> q;
    while (getline(cin,a)) { // 注意 while 处理多个 case
        string temp = a.substr(a.rfind('\\')+1,a.size());
        string l = temp.substr(0,temp.find(' '));
        string r = temp.substr(temp.find(' ')+1,temp.size());
        // l = l.substr(l.rfind('\\')+1,l.size());
        // cout<<l<<"kong"<<r<<endl;
        if(l.size()>=16)
         l = l.substr(l.size()-16,l.size());
        l = l+" "+r;
        if(m.find(l)== m.end())
        {
            if(q.size()<8)
            q.push(l);
            else
            {
                q.pop();
                q.push(l);
            }
        }
        m[l]++;
    }
    // cout<<q.size();
    int time = q.size();
    for(int i=0;i<time;i++)
    {
        string temp=q.front();
        string l = temp.substr(0,temp.find(' '));
        string r = temp.substr(temp.find(' ')+1,temp.size());
        l = l.substr(l.rfind('\\')+1,l.size());
        // cout<<l<<"kong"<<r<<endl;
        if(l.size()>=16)
         l = l.substr(l.size()-16,l.size());
        cout<<l<<' '<<r<<' '<<m[temp]<<endl;
        q.pop();
        
    }
    return 0;
}
// 64 位输出请用 printf("%lld")