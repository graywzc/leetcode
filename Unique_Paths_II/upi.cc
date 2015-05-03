class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int nRows = obstacleGrid.size();        
        if(0 == nRows) return 0;
        int nCols = obstacleGrid[0].size();
        if(0 == nCols) return 0;

        if(1 == obstacleGrid[0][0])
            return 0;
        else
            obstacleGrid[0][0] = 1;
            
        for(int i = 1; i < nCols; i++)
        {
            if(1 ==  obstacleGrid[0][i]) 
                obstacleGrid[0][i] = 0;
            else
                obstacleGrid[0][i] = obstacleGrid[0][i-1];
        }

        if(nRows == 1)
            return obstacleGrid[0][n-1];

        for(int i = 1; i < nRows; i++)
        {
            if(1!=obstacleGrid[i][0])
                obstacleGrid[i][0] = obstacleGrid[i-1][0];
            else
                obstacleGrid[i][0] = 0;

            for(int j = 1; j < nCols; j++) 
            {
                if(1!=obstacleGrid[i][j])     
                    obstacleGrid[i][j] = obstacleGrid[i][j-1] + obstacleGrid[i-1][j]; 
                else
                    obstacleGrid[i][j] = 0;
            }
        }

        return obstacleGrid[nRows-1][nCols-1];
    }
};
