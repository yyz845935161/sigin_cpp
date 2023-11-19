
#include <iostream>
using namespace std;
#include <set>
#include <vector>
#include <string>
#include <unistd.h>



//过不了 时间爆了
class Solution {
public:
    vector<vector<string>> ans;


    bool isPlace(int indexi, int indexj, vector<string>& board, int n)
    {

        if(board[indexi][indexj] == 'X' || board[indexi][indexj] == 'Q') return false;
        for(int i = 1; i <= n;i++)
        {
            if((board[indexi][i] == 'Q' && i!=indexj )|| (board[i][indexj] == 'Q'&& i!=indexi  )) return false;
        }

        for(int i = 1; i + indexi <=n+1 && i + indexj <=n+1; i++) //右下
        {
            if(board[i + indexi][i + indexj] == 'Q') return false;
        }

        for(int i = 1; indexi - i >= 1 && indexj -i >= 1; i++) //左上
        {
            if(board[indexi - i][indexj -i] == 'Q') return false;
        }

        for(int i = 1; indexi - i >= 1 && indexj +i  <=n+1; i++) // 右上
        {
            if(board[indexi - i][indexj +i] == 'Q') return false;
        }

        for(int i = 1;  i + indexi <=n+1 && indexj -i >= 1; i++)// 左下
        {
            if(board[indexi + i][indexj -i] == 'Q') return false ;
        }

        return true;
    }


    void traceBack(int indexi, int indexj, vector<string>& board, int& n, int k)
    {
        if(k == n)
        {
            vector<string> temp;
            for(int i = 1; i<=n;i++)
            {
                temp.push_back(board[i].substr(1,n));
            }
            ans.push_back(temp);
            return;
        }

        for(int i = indexi; i <= n; i++)
        {
            int j;
            if(indexi == i) j = indexj;
            else j = 1;
            for( ; j<= n; j++)
            {
                if(isPlace(i, j, board, n) )
                {
                    board[i][j] = 'Q';
                    traceBack(i, j+1, board, n, k + 1);
                    board[i][j] = '.';
                }

            }
        }

    }


    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n+2, string(n+2,'.'));
        for(int i = 0; i<=n+1; i++)
        {
            board[i][0] = 'X';
            board[0][i] = 'X';
            board[n+1][i] = 'X';
            board[i][n+1] = 'X';
        }

        traceBack(1, 1, board, n, 0);

        
        return ans;


    }
};


int main()
{
    vector<vector<string>> v = {{"MUC","LHR"},{"LHR","ABC"}};
    Solution a;
    a.solveNQueens(4);
    return 0;
}