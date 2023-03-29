// #include<iostream>
// #include<vector>
// using namespace std;

// int findSortindex(vector<int>&v,int pos)
// {
//     while(pos< v.size()-1 && v[pos]==v[pos+1])
//     {
//         pos++;
//     }
    
//     while(pos< v.size()-1 && v[pos]<v[pos+1])
//     {
//         pos++;
//         return pos+1;
//     }
//     while(pos< v.size()-1 && v[pos]>v[pos+1])
//     {
//         pos++;
//         return pos+1;
//     }
//     return pos+1;
    
// }

// int main()
// {
//     int n;
//     vector<int> v;
//     cin>>n;
//     int ans = 0;
//     for(int i = 0; i<n;i++ )
//     {
//         int temp;
//         cin>>temp;
//         v.push_back(temp);
//     }
//     int pos = 0;
//     while(v.size()>pos)
//     {

//         pos = findSortindex(v,pos);
//         if(pos < v.size())
//         ans++;
//     }
//     cout<<ans;
//     return 0;
    
    
// }

#include<iostream>
#include<vector>
using namespace std;



int main()
{
    int n;
    vector<int> v;
    cin>>n;
    int ans = 0;
    for(int i = 0; i<n;i++ )
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    for(int i=0;i<n;)
    {
        if(i <n && v[i]<v[i+1])
        {
            i++;
            while(i <n && v[i]<=v[i+1]){
                i++;
            }
            i++;
            ans++;
        }
        if(i <n && v[i]>v[i+1])
        {
            i++;
            while(i <n && v[i]>=v[i+1]){
                i++;
            }
            i++;
            ans++;
        }
        if(i <n && v[i]==v[i+1])
        {
            i++;
        }
        
    }
    
    
    
    cout<<ans;
    return 0;
    
    
}