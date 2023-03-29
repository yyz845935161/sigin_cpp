#include <iostream>
#include <stack>
using namespace std;



char getchar(int c)
{
    char a;
    int temp = abs(c);
    if(temp>9)
    {
         a = 'A' + temp-10;
    }
    else {
         a = '0' + temp;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    if(a<0) cout<<"-";
    // string ans;
    stack<char> st;
    while (a/b) {
        char c = getchar(a%b);
        st.push(c);
        a=a/b;
    }
    st.push(getchar(a%b));

    int n=st.size();
    

    for (int i=0; i<n; ++i) {
        cout<<st.top();
        st.pop();
    }
    return 0;

}
// 64 位输出请用 printf("%lld")



//day17的题

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    char c;
    cin>>c;
    
    if( c<= 'Z' && c>= 'A')
    {
        c = c - ('A' - 'a');
    }
    
    int ans=0;
    for(auto& i:s)
    {
        if(  i<= 'Z' && i>= 'A')
        {
            i = i - ('A' - 'a');
        }
        
        
        if(c == i)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}