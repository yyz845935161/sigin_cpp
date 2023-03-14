#include <iostream>
using namespace std;
#include <vector>

void find_y(vector<int>& y,int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%i == 0) y.push_back(i);
    }
}



int main() {
    int N, M;
    cin >> N >> M;
    vector<int> v;
    
    v.resize(M+1);
    v[N] = 1;

    for(int i =N;i<=M;i++)
    {
        vector<int> y;
        find_y(y,i);
        if(y.size()==0 || v[i]==0) continue;
        for(auto step: y)
        {
            if(i+step <= M  && (v[i+step] == 0 || v[i] + 1 < v[i+step]) ) 
            {
                v[i+step] = v[i] + 1;
            }
            // else if( v[i] + 1 < v[i+step])
            // {
            //     v[i+step] = v[i] + 1;
            // }
 
        }

    }
    for(auto i:v)
    cout<<i<<" ";
   
        
    }
// 64 位输出请用 printf("%lld")