#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:

    void FindPath(vector<vector<char>> &island,int i,int j)
    {
        

        island[i][j]='0';
        if(island[i+1][j]=='1')
        FindPath(island,i+1,j);
        if(island[i-1][j]=='1')
        FindPath(island,i-1,j);
        if(island[i][j+1]=='1')
        FindPath(island,i,j+1);
        if(island[i][j-1]=='1')
        FindPath(island,i,j-1);
    }


    int numIslands(vector<vector<char>>& grid) {
        int h= grid.size();
        int l= grid[0].size();
        vector<vector<char>> island(h+2,vector<char>(l+2,'0'));
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=l;j++)
            {
                island[i][j]=grid[i-1][j-1];
            }
        }
        int ans=0;

        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=l;j++)
            {
                if(island[i][j]=='1')
                {
                    FindPath(island,i,j);
                    ans++;
                }
            }
        }
        return ans;

    }
};