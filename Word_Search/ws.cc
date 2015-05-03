class Solution {
public:
    bool exist(vector<vector<char> > &board, string word, int i, int row, int col)
    {
        if(i == word.size()) 
            return true;
        else
        {
            if(row>0 && col<board[row-1].size() && board[row-1][col] == word[i])
            {
                board[row-1][col] = '\0';
                if(exist(board, word, i+1, row-1, col))
                    return true;
                board[row-1][col] = word[i];
            }
            if(row<(board.size()-1) && col < board[row+1].size() && board[row+1][col] == word[i])
            {
                board[row+1][col] = '\0';
                if(exist(board, word, i+1, row+1, col))
                    return true;
                board[row+1][col] = word[i];
            }
            if(col>0 && board[row][col-1] == word[i])
            {
                board[row][col-1] = '\0';
                if(exist(board, word, i+1, row, col-1))
                    return true;
                board[row][col-1] = word[i];
            }
            if(col < (board[row].size()-1) && board[row][col+1] == word[i])
            {
                board[row][col+1] = '\0';
                if(exist(board, word, i+1, row, col+1))
                    return true;
                board[row][col+1] = word[i];
            }

            return false;
        }
    }

    bool exist(vector<vector<char> > &board, string word) {
        if(word.size() ==  0)     
            return true;
        if(board.size() == 0)
            return false;
        for(int row = 0; row < board.size(); row++)
        {
            for(int col = 0; col < board[0].size(); col++)     
            {
                if( board[row][col] == word[0] ) 
                {
                    board[row][col] = '\0';
                    if(exist(board, word, 1, row, col))
                        return true;
                    board[row][col] = word[0];
                }
            }
        }

        return false;
        
    }
};
