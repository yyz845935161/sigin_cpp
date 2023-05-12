#include<iostream>
#include<vector>
#include<set>
using namespace std;


//空间超了
class Solution {
public:

    void findPath(const vector<vector<int>>& vv,int j,set<int>& ans)
    {
        ans.insert(j);
        for(int i=j;i<vv.size();i++)
        {
            if(vv[j][i]==1) findPath(vv,i,ans);
        }
    }

    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> vv(n,vector<int>(n,0));
        set<int> s;
        for(int i=0;i<restricted.size();i++)
        {
            s.insert(restricted[i]);
        }

        for(int i=0;i<n-1;i++)
        {
            if(s.find(edges[i][0]) !=s.end() || s.find(edges[i][1]) !=s.end())
            {
                continue;
            }
            else
            {
                vv[edges[i][0]][edges[i][1]] = 1;
                vv[edges[i][1]][edges[i][0]] = 1;
            }
        }
        set<int> ans;

        findPath(vv,0,ans);

        return ans.size()-1;

    }
};

int main()
{
    Solution a;
    int n =  7;
    vector<vector<int>> vv= {{0,1},{1,2},{3,1},{4,0},{0,5},{5,6}};
    vector<int> v= {4,5};
    a.reachableNodes(n,vv,v);
    return 0;
}