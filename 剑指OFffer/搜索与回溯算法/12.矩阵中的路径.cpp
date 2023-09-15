class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(dfs(board,word,i,j,0)) return true;
            }
        }

        return false;
    }


    
bool dfs(vector<vector<char>>& board,const string& word, int i,int j,int k)
{
    if(i<0 || i>= board.size() || j<0 || j>=board[0].size() || board[i][j] != word[k] ) return false;

    if(k == word.size()-1) return true;

    board[i][j] = '\0';

    bool res = dfs(board,word,i+1,j,k+1) || dfs(board,word,i-1,j,k+1) || dfs(board,word,i,j+1,k+1) || dfs(board,word,i,j-1,k+1);
    
    board[i][j] = word[k];

    return res;


}

};

