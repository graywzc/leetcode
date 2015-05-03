
class Solution {
public:

    void rotate(vector<vector<int> > &matrix) {
        if(matrix.size() == 1)
            return;
        double size = matrix.size();
        double center = (size-1)/2;
        for(int i = 0; i <= center; i++)
            for(int j = 0; j < center; j++)
            {
                double x = j - center; 
                double y = size - 1 - i - center;
                int temp1 = matrix[i][j];
                int temp2;
                for(int k = 0; k < 4; k++) 
                {
                    double newx = y;  
                    double newy = -x;
                    int ii = (int)(size - 1 - center - newy); 
                    int jj = (int)(newx + center); 
                    temp2 = matrix[ii][jj];
                    matrix[ii][jj] = temp1;
                    temp1 = temp2;
                    x = newx;
                    y = newy;
                }
                
            }
    }
};
