# include <stdio.h>
# include <vector>
# include <limits.h>
using namespace std;
class Solution {
public:
    static int maximalRectangle(vector<vector<char> > &matrix) {
        int nRows = matrix.size();
        if(nRows == 0)
            return 0;
        
        int maxr = 0;
        for(int row = 0; row < nRows; row++)
        {
            int nCols = matrix[row].size();
            for(int col = 0; col < nCols; col++)
            {
                if(matrix[row][col]=='1') 
                {
                    int local_maxr = 0;
                    int maxSpan = INT_MAX; 
                    for(int i = row; i < nRows; i++)
                    {
                        int j = col; 
                        int icol = matrix[i].size();
                        while(j < icol && matrix[i][j] == '1')
                            j++;
                        if(j == col)
                            break;
                        if((j-col) < maxSpan)
                            maxSpan = j-col;
                        
                        int rec = maxSpan*(i - row + 1);
                        if(rec > local_maxr)
                            local_maxr = rec;
                    }
                    if (local_maxr > maxr)
                        maxr = local_maxr;
                }
            }
        }
        return maxr;
    }
};

int  main()
{
    vector<vector<char> > matrix;
    vector<char> row(5,'1');
    matrix.push_back(row);
    matrix.push_back(row);
    matrix.push_back(row);
    matrix.push_back(row);
    matrix[0][1] = '0';
    matrix[0][3] = '0';
    matrix[3][0] = '0';
    matrix[3][2] = '0';
    matrix[3][4] = '0';
    matrix[0][3] = '0';

    int res = Solution::maximalRectangle(matrix);
    printf("%d\n", res);
}
