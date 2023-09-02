#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>>& v,int i, int j,int val)
{
    if(i<0 || i>=v.size() || j<0 || j>= v[0].size())
    {
        return;
    }
    if(v[i][j] != val) return;
    v[i][j] = 0;

    dfs(v,i+1, j,val);
    dfs(v,i, j+1,val);
    dfs(v,i-1, j,val);
    dfs(v,i, j-1,val);


}


int main()
{
    int n,m;
    while (cin >> n >>m)
    {
        vector<vector<int>> v(n,vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j<m;j++)
            {
                cin>>v[i][j];
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j<m;j++)
            {
                if(v[i][j] != 0 )
                {
                    if(i-1>=0 && v[i-1][j] == v[i][j])
                    {
                        dfs(v,i,j,v[i][j]);
                    }
                    if(i+1<v.size() && v[i+1][j] == v[i][j])
                    {
                        dfs(v,i,j,v[i][j]);
                    }
                    if(j-1>= 0 && v[i][j-1] == v[i][j])
                    {
                        dfs(v,i,j,v[i][j]);
                    }
                    if(j+1<v[0].size() && v[i][j+1] == v[i][j])
                    {
                        dfs(v,i,j,v[i][j]);
                    }

                }
                

            }

        }


        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j<m;j++)
            {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
    
}