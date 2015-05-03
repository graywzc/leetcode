class Solution {
public:

    bool isValid(int r1, int r2, int c1, int c2)
    {
        if(c1 == c2) 
            return false;
        if((r2-r1) == abs(c1-c2))
            return false;
        return true;
    }

    void nQueen(int n, int cur, int *board, int &res)
    {
        if(cur == n) 
        {
            res++;
            return;
        }
        else
        {
            for(int i = 0; i < n; i++) 
            {
                bool pass = true;        
                for(int j = 0; j < cur; j++) 
                {
                    if(!isValid(j,cur,board[j], i))  
                    {
                        pass=false; 
                        break;
                    }    
                }
                if(pass)
                {
                    board[cur] = i; 
                    nQueen(n, cur+1, board, res);
                }
            }
            return;
        }
    }

    int totalNQueens(int n) {
        int res = 0;    
        if(n == 0)
            return res;
        int *board = new int[n];
        nQueen(n, 0, board, res); 
        delete [] board;
        return res;
    }
};
