// class Bonus {
// public:
//     int depgetMost(vector<vector<int> > board,int i,int j)
//     {
//         if(i==5&&j==5)
//         {
//             return board[i][j];
//         }
        
//         if(i==5)
//         {
//             return depgetMost(board,i,j+1) + board[i][j];
//         }
//         if(j==5)
//         {
//             return depgetMost(board,i+1,j) + board[i][j];
//         }
//         else
//         {
//             return max(depgetMost(board,i+1,j) + board[i][j],depgetMost(board,i,j+1) + board[i][j]);
//         }
//     }
    
//     int getMost(vector<vector<int> > board) {
//         // write code here
        
//      return depgetMost(board,0,0);
//     }
// };

#include<iostream>
#include<vector>
using namespace std;
int n,m;
vector<int> v;
vector<vector<int>> vv;
vector<vector<int>> temp_path;
vector<vector<int>> best_path;

void casepath(int i,int j)
{
    if(i>=n || i <0 || j>=m || j<0) return;
    if(vv[i][j]==1) return;
    vv[i][j]=0;
    temp_path.push_back({i,j});
    if(i==n-1 && j==m-1)
    {
        if(!temp_path.empty() && best_path.size()>temp_path.size())
        {
            best_path=temp_path;
        }
    }
    
    casepath(i+1,j);
    casepath(i,j+1);
    casepath(i-1,j);
    casepath(i,j-1);
    vv[i][j]=1;
    temp_path.pop_back();
}



int main()
{
    
    while(cin>>n>>m)  
    {
        vv.resize(n,vector<int>(m,0));
        temp_path.clear();
        best_path.clear();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>vv[i][j];
            }
        }


        casepath(0,0);
        
        for(auto e:vv)
        {
            cout<<'('<<e[0]<<','<<e[1]<<')'<<endl;
        }
        
         return 0;       
    }
    
    
    
}