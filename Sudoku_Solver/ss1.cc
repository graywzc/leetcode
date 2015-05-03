// write the bfs approach
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:

    static bool findEmpty(const vector<vector<char> > &cur, int &row, int &col)
    {
        for(int i = 0; i < 9; i++) 
            for(int j = 0; j < 9; j++)
            {
                if(cur[i][j] == '.') 
                {
                    row = i;
                    col = j;
                    return true;
                }
            }
        return false;
    }
    static void solveSudoku(vector<vector<char> > &board) {
        queue<vector<vector<char> > > qu;                    
        qu.push(board);
        
        while(!qu.empty())
        {
            vector<vector<char> > cur = qu.front();  
            qu.pop();
            int row, col;
            if(findEmpty(cur, row, col) == false)
            {
                board = cur; 
                return;
            }
            else
            {
                bool suggested[9] = {true,true,true,true,true,true,true,true,true}; 
                for(int i = 0; i < 9; i ++)
                    if(cur[row][i]!='.')
                        suggested[cur[row][i]-'1'] = false;
                for(int i = 0; i < 9; i ++)
                    if(cur[i][col]!='.')
                        suggested[cur[i][col]-'1'] = false;
                for(int i = 0; i < 9; i ++)
                {
                    int irow = (int)(row/3)*3 + (int)(i/3);
                    int icol = (int)(col/3)*3 + i%3;
                    if(cur[irow][icol]!='.') 
                        suggested[cur[irow][icol]-'1'] = false;
                }

                for(int i = 0;  i < 9; i ++) 
                {
                    if(suggested[i] == true) 
                    {
                        cur[row][col] = '1'+i;  
                        qu.push(cur);
                    }
                }
            }
        }
        
    }
};

int main()
{
    vector<vector<char> > board(9,vector<char>(9,'.'));

    board[0][1] = '1'; 
    board[0][2] = '6'; 
    board[0][5] = '2'; 
    board[1][4] = '1'; 
    board[1][8] = '5'; 
    board[2][5] = '4'; 
    board[2][7] = '6'; 
    board[3][2] = '3'; 
    board[3][8] = '7'; 
    board[5][0] = '5'; 
    board[5][3] = '8'; 
    board[5][6] = '1'; 
    board[6][1] = '8'; 
    board[7][0] = '3'; 
    board[7][3] = '1'; 
    board[7][4] = '9'; 
    board[7][6] = '7'; 
    board[8][6] = '3'; 
    
    Solution::solveSudoku(board);
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++) 
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
