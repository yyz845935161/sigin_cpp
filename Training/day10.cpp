
#include<iostream>
#include <vector>

class Board {
  public:

    bool checkWon(vector<vector<int>> board) {
        // write code here
        int row = board.size();

        int temp=0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row; j++) {
                temp+=board[i][j];
            }
            if((temp) == row) return true;
            else temp=0;
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row; j++) {
                temp+=board[j][i];
            }
            if((temp) == row) return true;
            else temp=0;
        }

        for(int i=0;i<row;i++)
        {
            temp+=board[i][i];
        }
        if((temp) == row) return true;
            else temp=0;
        
        for(int i=0;i<row;i++)
        {
            temp+=board[i][row-i];
        }
        if((temp) == row) return true;
            else temp=0;

        return false;



    }
};