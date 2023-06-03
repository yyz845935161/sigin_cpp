// class Gift {
// public:
//     int getValue(vector<int> gifts, int n) {
//         // write code here
//         int ans=gifts[0];
//         int count=1;
//         vector<int> v;
//         v.resize(100000,0);
//         for(int i=0;i<n;i++)
//         {
//             v[gifts[i]]++;
//         }
//         for(auto e:gifts)
//         {
//             if(v[e] > n/2) return e;
//         }
//         return 0;
//     }
// };


// 时间复杂度过不了
// #include<iostream>
// #include<string>
// using namespace std;

// int ThreeMin(const int& a,const int& b,const int& c)
// {
//     int temp=a>b?b:a;
//     return temp>c?c:temp;
// }

// int Distance(const string& s1,const string& s2,int i,int j)
// {
//     if(i==s1.size() && j==s2.size()) return 0;
//     if(i==s1.size()) return s2.size()-j;
//     if(j==s2.size()) return s1.size()-i;
//     if(s1[i]==s2[j]) return Distance(s1,s2,i+1,j+1);
//     else
//     {
//         return ThreeMin(Distance(s1,s2,i+1,j+1)+1, Distance(s1,s2,i+1,j)+1, Distance(s1,s2,i,j+1)+1);
//     }
// }



// int main()
// {
//     string s1,s2;
//     cin>>s1>>s2;
    
//     cout<<Distance(s1,s2,0,0);
    
//     return 0;
// }

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int minDistance(const string& s1,const string& s2)
{
    if(s1.empty() || s2.empty())
    {
        return max(s1.size(),s2.size());
    }
    vector<vector<int>> v(s1.size()+1,vector<int>(s2.size()+1,INT16_MAX));
    for(int i=0;i<=s1.size();i++)
        v[i][0] = i;
    for(int i=0;i<=s2.size();i++)
        v[0][i] = i;
    
    for(int i=1;i<=s1.size();i++)
    {
        for(int j=1;j<=s2.size();j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                v[i][j] = min(v[i-1][j],v[i][j-1])+1;
                v[i][j] = min(v[i][j],v[i-1][j-1]);
            }
            else
            {
                v[i][j] = min(v[i-1][j],v[i][j-1])+1;
                v[i][j] = min(v[i][j],v[i-1][j-1]+1);
            }
        }
    }
    return v[s1.size()][s2.size()];
    
    
}


int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        cout<< minDistance(s1,s2)<<endl;
    }
    
    
    
    return 0;
}