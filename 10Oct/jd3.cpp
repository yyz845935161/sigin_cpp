#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;


bool isEage(vector<vector<char>>& board,int i, int j,  char enemy)
{
    if( (board[i-1][j] == enemy && board[i+1][j] == enemy) || (board[i][j-1] == enemy && board[i][j+1] == enemy) )
    {
        return true;
    }
    return false;
}


int main()
{
    int n;
    cin>>n;
    for(int time=0;time<n;time++)
    {
        vector<vector<char>> board(5,vector<char>(5,'.')); //5*5不用处理越界
        for(int i = 1;i<=3;i++)
        {
            for(int j = 1;j<=3;j++)
            {
                cin>>board[i][j];
            }
        }

        bool kou = false;  //小红  *
        bool yukari = false; //小紫 o

        for(int i = 1;i<=3;i++)
        {
            for(int j = 1;j<=3;j++)
            {
                if(board[i][j] == '*')
                {
                    if(isEage(board,i, j, 'o')) kou = true;      
                }
                else if(board[i][j] == 'o')
                {
                    if(isEage(board,i, j, '*')) yukari = true;      
                }

               
            }
        }
        if(kou && yukari)
        {
            cout<<"draw"<<endl;
        }
        else if(kou)
        {
            cout<<"yukari"<<endl;
        }
        else if(yukari)
        {
            cout<<"kou"<<endl;
        }
    }
}



/*3
...
o*o
...
o**
ooo
..*
o*o
*o*
o*o


*/