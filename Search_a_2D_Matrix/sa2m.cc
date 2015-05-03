class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size() == 0)
            return false;
        int nRows = matrix.size();        
        if(matrix[0].size() == 0)
            return false;
        int nCols = matrix[0].size();
        int size = nRows*nCols;
        int start = 0, end = size-1;
        while(start<=end)
        {
            int mid = (start+end)/2; 
            int iRow = mid/nCols;
            int iCol = mid%nCols;
            if(matrix[iRow][iCol] == target)
                return true;
            else if(matrix[iRow][iCol] > target)
                end = mid-1;  
            else
                start = mid+1;
        }
        return false;
    }
};
