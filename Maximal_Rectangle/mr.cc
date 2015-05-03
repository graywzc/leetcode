#include <stdio.h>
#include <vector>
#include <algorithm>

// This is my first solution, but it cannot handle the following scenario 
/*
 * 1 0 1 0 1
 * 1 1 1 1 1
 * 1 1 1 1 1
 * 0 1 0 1 0
 * */

using namespace std;

class Solution {
public:
    static int maximalRectangle(const vector<vector<char> > &matrix, int start, int end)
    {
        if(start == end) 
        {
            int max = 0; 
            int connected = 0;
            for(int i = 0; i < matrix[start].size(); i++)
            {
                if(matrix[start][i] == '1')     
                {
                    connected ++;
                    if(connected > max)
                        max = connected;
                }
                else
                    connected = 0;
            }

            return max;
        }
        else
        {
            int mid = (start + end)/2; 
            int upper_max = maximalRectangle(matrix, start, mid);
            int lower_max = maximalRectangle(matrix, mid+1, end);

            int maxr = max(lower_max, upper_max);

            if(upper_max == 0) 
                return lower_max;
            else if(lower_max == 0)
                return upper_max;
            else
            {
                int nCols = matrix[start].size();
                for(int i = 0; i < nCols; i++) 
                {
                    if(matrix[mid][i]!='0' && matrix[mid+1][i]!='0') 
                    {
                        int up = mid - 1; 
                        while(up >= start && matrix[up][i] == '1')
                            up--;
                        int down = mid + 2;
                        while(down <= end && matrix[down][i] == '1')
                            down++;

                        int combine_max = down - up - 1;

                        int left = i - 1;
                        while(left >= 0)
                        {
                            bool hit0 = false;
                            for(int j = up+1; j <= down-1; j++) 
                            {
                                if(matrix[j][left] == '0') 
                                {
                                    hit0 = true; 
                                    break;
                                }
                            }
                            if(hit0)
                                break;
                            else
                            {
                                left --;
                                combine_max += (down-up-1);
                            }
                        }

                        int right = i+1;
                        while(right < nCols)
                        {
                            bool hit0 = false; 
                            for(int j = up+1; j <= down-1; j++)
                            {
                                if(matrix[j][right] == '0') 
                                {
                                    hit0 = true; 
                                    break;
                                }
                            }
                            if(hit0)
                                break;
                            else
                            {
                                right++; 
                                combine_max += (down-up-1);
                            }
                        }
                        
                        if(combine_max > maxr)
                            maxr = combine_max;
                    }
                }
            }
            return maxr;

        }
    }
    static int maximalRectangle(vector<vector<char> > &matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)                
            return 0;
        return maximalRectangle(matrix, 0, matrix.size()-1);
    }
};

int  main()
{
    vector<vector<char> > matrix;
    vector<char> row(4,'1');
    matrix.push_back(row);
    matrix.push_back(row);
    matrix.push_back(row);

    int res = Solution::maximalRectangle(matrix);
}
