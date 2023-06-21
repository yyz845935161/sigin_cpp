class Solution {
public:

    void FindNum(vector<string>& chessboard,int i,int j)
    {
        if(i<0 || j<0 || i==chessboard.size() || j==chessboard[0].size())   
        return;

        if(i-1>=0 && chessboard[i-1][j]=='O')
    }

    int ans=0;
    int temp_max=0;
    vector<vector<int>> eat;
    int flipChess(vector<string>& chessboard) {
        for(int i=0;i<chessboard.size();i++)
        {
            for(int j=0;j<chessboard[0].size();j++)
            {
                if(chessboard[i][j]=='.')
                FindNum(chessboard,i,j);
            }
        }
    }
};