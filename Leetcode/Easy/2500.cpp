#include<iostream>
using namespace std;
#include<set>
#include<vector>
#include<algorithm>
struct Less
{
bool operator()(const int & a,const int& b)
{
    return a>b;
}

};

class Solution {
public:
    int deleteGreatestValue(vector<vector<int> > & grid) {
        for(int i=0;i<grid.size();i++)
        {
            sort(grid[i].begin(),grid[i].end());
        }
        int ans=0;
        for(int i=0;i<grid[0].size();i++)
        {
            set<int,Less> s;
            for(int j=0;j<grid.size();j++)
            {
                s.insert(grid[j][i]);
            }
            cout<<(*s.begin())<<" ";
            ans+=(*s.begin());
        }

        return ans;
    }
};

int main()
{
    Solution a;
    vector<vector<int> > v{{1,2,3},{2,3,4}};
    a.deleteGreatestValue(v);
    return 0;
}