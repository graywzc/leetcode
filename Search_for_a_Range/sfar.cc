class Solution {
public:
    int binarySearch(int A[], int start, int end, int target)
    {
        if(start>end)     
            return -1;
        
        int mid = (start+end)/2;
        if(A[mid] == target)
            return mid;
        else if (A[mid] > target)
        {
            return binarySearch(A, start, mid-1, target); 
        }
        else
            return binarySearch(A, mid+1, end, target);
    }
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        int idx = binarySearch(A, 0, n-1, target); 
        if(-1 != idx)
        {
            int idx1 = idx; 
            while(idx1>0 && A[idx1-1] == target)
                idx1--;
            int idx2 = idx;
            while(idx2<n-1 && A[idx2+1] == target)
                idx2++;

            res[0] = idx1;
            res[1] = idx2;
        }

        return res;
    }
};
