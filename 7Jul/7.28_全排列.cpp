#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
int main()
{
    vector<int> v = {3,2,7,1};
    sort(v.begin(),v.end());
    do
    {
        /* code */
        for(auto e:v)
        {
            cout<<e<<" ";
            
        }
        cout<<endl;
    } while (next_permutation(v.begin(),v.end()));
    
    return 0;
}