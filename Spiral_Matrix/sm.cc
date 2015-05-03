#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    static void spiralOrder(const vector<vector<int> > &matrix, vector<int> &res, int x1, int x2, int y1, int y2)
    {
        if(x1>x2 || y1>y2) 
            return;
        else if(x1 == x2)
        {
            for(int i = y1; i <= y2; i++) 
                res.push_back(matrix[x1][i]);
            return;
        }
        else if(y1 == y2)
        {
            for(int i = x1; i <= x2; i++) 
                res.push_back(matrix[i][y1]);
            return;
        }
        else
        {
            for(int i = y1; i < y2; i++)    
            {
                res.push_back(matrix[x1][i]); 
            }
            for(int i = x1; i < x2; i++)
            {
                res.push_back(matrix[i][y2]); 
            }
            for(int i = y2; i > y1; i--)
            {
                res.push_back(matrix[x2][i]); 
            }
            for(int i = x2; i > x1; i--)
            {
                res.push_back(matrix[i][y1]); 
            }
            spiralOrder(matrix, res, x1+1, x2-1, y1+1, y2-1);
            return;
        }
    }
    static vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;            
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return res;
        spiralOrder(matrix, res, 0, matrix.size()-1, 0, matrix[0].size() - 1);

        return res;
    }
};

int main()
{
    vector<vector<int> > matrix(4, vector<int>(3,0));
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;
    vector<int> res = Solution::spiralOrder(matrix);
    for(int i = 0; i < res.size(); i++)
        printf("%d ",res[i]);
    printf("\n");

}

