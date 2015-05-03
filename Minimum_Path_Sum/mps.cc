class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int nRows = grid.size();        
        if(nRows == 0) return 0;
        int nCols = grid[0].size();
        if(nCols == 0) return 0;

        vector<int> r1(nCols);
        r1[0] = grid[0][0];
        for(int i = 1; i < nCols; i++)
            r1[i] = grid[0][i] + r1[i-1]; 
        if(nRows == 1)
            return r1[nCols-1];

        int start = grid[0][0];

        vector<int> r2(nCols);
        for(int i = 1; i < nRows; i++)
        {
            start += grid[i][0];
            r2[0] = start; 
            for(int j = 1; j < nCols; j++)
                r2[j] = grid[i][j] + ((r1[j]>r2[j-1])?r2[j-1]:r1[j]);
            r1 = r2;
        }

        return r1[nCols-1]; 

    }
};
