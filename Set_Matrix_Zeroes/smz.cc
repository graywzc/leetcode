class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int nRows = matrix.size();
        if(nRows == 0) return;
        int nCols = matrix[0].size();
        if(nCols == 0) return;
        bool firstrow0 = false;
        bool firstcol0 = false;
        for(int i = 0; i < nCols; i++)
        {
            if(matrix[0][i] == 0) 
                firstrow0 = true;
        }
        for(int i = 0; i < nRows; i++)
        {
            if(matrix[i][0] == 0) 
                firstcol0 = true;
        }
        for(int i = 1; i < nRows; i++)
            for(int j = 1; j < nCols; j++)
            {
                if(matrix[i][j] == 0) 
                {
                    matrix[i][0] = 0; 
                    matrix[0][j] = 0;
                }
            }
        for(int i = 1; i < nRows; i++)
        {
            if(matrix[i][0] == 0) 
                matrix[i].assign(nCols, 0); 
        }
        for(int i = 1; i < nCols; i++)
        {
            if(matrix[0][i] == 0) 
            for(int j = 0; j < nRows; j++)
                matrix[j][i] = 0;
        }
        if(firstrow0)
            matrix[0].assign(nCols, 0);
        if(firstcol0)
        {
            for(int i = 0; i < nRows; i++) 
                matrix[i][0] = 0;
        }
    }
};
