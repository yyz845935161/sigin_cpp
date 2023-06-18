class Solution {
public:
    int ans=0;
    int row ;
    int l ;
    bool iserge = true;
    void FindPath(vector<vector<int>>& grid,int i,int j)
    {
        if(i < 0|| i==row || j<0||j==l) 
        {
            iserge=false;
            return;
        }
        if(grid[i][j] !=0) return; 

        

        grid[i][j]=1;
         FindPath(grid,i+1,j);
        FindPath(grid,i,j+1);
         FindPath(grid,i-1,j);
        FindPath(grid,i,j-1);
    }


    int closedIsland(vector<vector<int>>& grid) {
        row = grid.size();
        l = grid[0].size();

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<l;j++)
            {

                if(grid[i][j]==0)
                {
                   
                    FindPath(grid,i,j);
                    if(iserge)
                    {
                        ans++;
                    }
                    
                    iserge = true;
                    // for(auto e:grid)
                    // {
                    //     for(auto k:e)
                    //     {
                    //         cout<<k<<" ";
                    //     }
                    //     cout<<endl;
                    // }


                }
            }
        }
        return ans;
    }
};