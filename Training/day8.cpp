#include <iostream>
#include <vector>
using namespace std;
#include<queue>

struct lexico {
    bool operator()(const string& s1, const string& s2) {
        int min = s1.size()>s2.size()?s2.size():s1.size();

        for(int i=0;i<min;i++) {
            if(s1[i]!=s2[i])
                return s1[i]>s2[i];
        }
        return s1.size()>s2.size();
    }
};



struct len {
    bool operator()(const string& s1, const string& s2) {

        return s1.size()>s2.size();
    }
};


int main() {
    int a;
    cin >> a;
    vector<string> v(a);
    priority_queue<string, vector<string>, lexico> l;
    priority_queue<string, vector<string>, len> le;
    for (int i = 0; i < a; i++) {
        cin >> v[i];
        l.push(v[i]);
        le.push(v[i]);
    }

    bool blex = true;
    bool blen = true;

    for (int i = 0; i < a; i++) {
        if(v[i]!= l.top()) blex=false;
        if(v[i]!=le.top()) blen=false;
        l.pop();
        le.pop();
        if(!blex && !blen) break;
    }

    if(blex && blen) cout<<"both"<<endl;
    
    else if(blex) cout<<"lexicographically"<<endl;
    else if(blen) cout<<"lengths"<<endl;
    else cout<<"none"<<endl;

    return 0;








}
// 64 位输出请用 printf("%lld")

#include <iostream>
using namespace std;

int maxInx( int a, int b)
{
    int c=a%b;
    while (c) {
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}

int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
    cout<<a*b/maxInx(a,b)<<endl;
        
    }
    return 0;
}
// 64 位输出请用 printf("%lld")