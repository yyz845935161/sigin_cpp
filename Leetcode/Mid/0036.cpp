class Solution {
public:

    bool cheakH(int i,int j,vector<vector<char>>& board)
    {
        int hash[256] = {0};
        for(int h=0;h<9;h++)
        {
            if(board[i][h]!='.')
            {
                hash[board[i][h]]++;
                if(hash[board[i][h]]>1)
                {
                    return false;
                }
            }
        }
        return true;
    }
        
    bool cheakL(int i,int j,vector<vector<char>>& board)
    {
        int hash[256] = {0};
        for(int h=0;h<9;h++)
        {
            if(board[h][j]!='.')
            {
                hash[board[h][j]]++;
                if(hash[board[h][j]]>1)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool cheakK(int i,int j,vector<vector<char>>& board)
    {
        int beginx=0;
        int beginy=0;
        if(i<=2) 
        {
            beginx=0;
        }
        else if(i<=5)
        {
            beginx=3;
        }
        else if(i<=8)
        {
            beginx=6;
        }
        
        if(j<=2) 
        {
            beginy=0;
        }
        else if(j<=5)
        {
            beginy=3;
        }
        else if(j<=8)
        {
            beginy=6;
        }

        int hash[256] = {0};
        for(int h=beginx;h<beginx+3;h++)
        {
            for(int l=beginy;l<beginy+3;l++)
            {
                if(board[h][l]<='9' && board[h][l]>='0')
                {
                    // cout<<board[h][l]<<' ';
                    hash[board[h][l]]++;
                    if(hash[board[h][l]]>1)
                    {
                        return false;
                    }
                }

            }
        }
        return true;
    }



    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j] != '.')
                {
                    if(cheakH(i,j,board) && cheakL(i,j,board) && cheakK(i,j,board))
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};