
class Solution {
public:
    bool tryNext(vector<vector<char> > &board, int row, int col)
    {
        if(row == 8 && col == 8) 
            return true;
        else
        {
            if(col < 8) 
                return solveSudoku(board, row, col+1);
            else
                return solveSudoku(board, row+1, 0);
        }
         
    }
    bool solveSudoku(vector<vector<char> > &board, int row, int col)
    {
        if(board[row][col]!='.')
        {
            return tryNext(board, row, col);    
        }
        else
        {
            bool suggested[9]={true, true, true, true,true, true, true, true,true };
            for(int i = 0; i < 9; i ++)
                if(board[row][i]!='.')
                    suggested[board[row][i]-'1'] = false;
            for(int i = 0; i < 9; i ++)
                if(board[i][col]!='.')
                    suggested[board[i][col]-'1'] = false;
            for(int i = 0; i < 9; i ++)
            {
                int irow = (int)(row/3)*3 + (int)(i/3);
                int icol = (int)(col/3)*3 + i%3;
                if(board[irow][icol]!='.') 
                    suggested[board[irow][icol]-'1'] = false;
            }
            for(int i = 0; i < 9; i++)
            {
                if(suggested[i] == true)  
                {
                    board[row][col] = '1'+i; 
                    if(tryNext(board, row, col))
                        return true;
                }
            }
            board[row][col] = '.';
            return false;
        }
    }
    
    void solveSudoku(vector<vector<char> > &board) {
        solveSudoku(board, 0, 0);            
    }
};

