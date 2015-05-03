class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int nRows = triangle.size();        
        if(0 == nRows) return 0;
        else if(1 == nRows) return triangle[0][0];
        else
        {
            for(int i = nRows-2; i>=0; i--) 
            {
                for(int j = 0;  j <= i; j++)     
                {
                    triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
                }
            }
            return triangle[0][0];
        }
    }
};
