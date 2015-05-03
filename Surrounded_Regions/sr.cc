class Solution {
public:

    void mark(vector<vector<char>> &board, int row, int col)
    {
        board[row][col] = 'Y'; 
        if(row>0 && board[row-1][col] == 'O')
            mark(board, row-1, col);
        if(row<(board.size()-1) && board[row+1][col] == 'O')
            mark(board, row+1, col);
        if(col>0 && board[row][col-1] == 'O')
            mark(board, row, col-1);
        if(col<(board[0].size()-1) && board[row][col+1] == 'O')
            mark(board, row, col+1);
    }

    void solve(vector<vector<char>> &board) {
        int nRows = board.size();        
        if(nRows <= 2)
            return;
        
        int nCols = board[0].size();
        if(nCols <= 2)
            return;

        for(int i = 0; i < nRows; i++)
        {
            if(board[i][0] == 'O') 
                mark(board, i, 0);
            if(board[i][nCols-1] == 'O')
                mark(board, i, nCols-1);
        }
        for(int j = 1; j < nCols-1; j++)
        {
            if(board[0][j] == 'O') 
                mark(board, 0, j);
            if(board[nRows-1][j] == 'O')
                mark(board, nRows-1, j);
        }

        for(int i = 0; i < nRows; i++)
            for(int j = 0; j < nCols; j++)
            {
                if(board[i][j] == 'O') 
                    board[i][j] = 'X';
                else if(board[i][j] == 'Y')
                    board[i][j] = 'O';
            }

        
        return;
    }
};
