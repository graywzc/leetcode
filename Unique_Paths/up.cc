class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1)
            return 1;
        int *row1 = new int[n];
        int *row2 = new int[n];

        for(int i = 0; i < n; i++)
            row1[i] = 1; 
        row2[0] = 1;

        for(int i = 0; i < m - 1; i++)
        {
            for(int j = 1; j < n; j++) 
            {
                row2[j] = row2[j-1] + row1[j]; 
            }
            memcpy(row1, row2, sizeof(int)*n);
        }
        
        int res = row2[n-1];


        delete [] row1;
        delete [] row2;

        return res;
    }
};
