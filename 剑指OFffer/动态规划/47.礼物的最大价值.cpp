
//不行， 时间超了

struct Ind
{
    int _x;
    int _y;
    int _val;
    Ind(int x,int y, int val):
    _x(x),
    _y(y),
    _val(val)
    {}
};


class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<Ind> q;
        int max = 0;
        q.push(Ind(0,0,grid[0][0]));
        while(!q.empty())
        {
            Ind temp = q.front();
            if(temp._x + 1< m)
            {
                q.push(Ind(temp._x+1,temp._y,temp._val + grid[temp._x+1][temp._y]));
            }
            if(temp._y +1 < n)
            {
                q.push(Ind(temp._x,temp._y+1,temp._val + grid[temp._x][temp._y+1]));
            }
            if(temp._x == m-1 && temp._y==n-1 )
            {
                max = temp._val  > max ? temp._val :max;
            }

            q.pop();

        }
        return max;


    }
};



class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int left = 0;
                int up = 0;
                if( i >= 1) left = ans[i-1][j];
                if( j >= 1) up = ans[i][j-1];

                ans[i][j] = grid[i][j];
                ans[i][j] = max(ans[i][j] +left,ans[i][j]+up );
                cout<<ans[i][j]<<" ";
            }
        }

        return ans[m-1][n-1];
        


    }
};