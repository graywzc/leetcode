class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        
        int n = board.size();            
        if(n!= 9) return false;
        for(int i = 0; i < n; i++)
            if(board[i].size()!=9) return false;

        int chker[9];
        
        for(int i = 0; i < n; i++)
        {
            memset(chker, 0, sizeof(int)*9);
            for(int j = 0; j < n; j++)     
                if(board[i][j]!='.')
                {
                    if(chker[board[i][j] - '1'] == 1)
                        return false;
                    else
                        chker[board[i][j] - '1'] = 1;       
                }
        }

        for(int i = 0; i < n; i++)
        {
            memset(chker, 0, sizeof(int)*9);
            for(int j = 0; j < n; j++)     
                if(board[j][i]!='.')
                {
                    if(chker[board[j][i] - '1'] == 1)
                        return false;
                    else
                        chker[board[j][i] - '1'] = 1;       
                }
        }

        for(int i = 0; i < n; i++)
        {
            int rshift1 = (i/3) * 3;  
            int cshift1 = (i%3) * 3;
            memset(chker, 0, sizeof(int)*9);
            for(int j = 0; j < n; j++) 
            {
                int rshift2 = j/3; 
                int cshift2 = j%3;
                int ridx = rshift1 + rshift2;
                int cidx = cshift1 + cshift2;
                if(board[ridx][cidx]!='.')
                {
                    if(chker[board[ridx][cidx] - '1'] == 1)           
                        return false;
                    else
                        chker[board[ridx][cidx] - '1'] = 1;
                }
            }
        }

        return true;
        
    }
};
