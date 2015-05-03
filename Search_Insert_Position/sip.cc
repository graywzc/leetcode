class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n == 0)     
            return 0;
        if(target<= A[0])
            return 0;
        if (target > A[n-1])
            return n;

        int start = 0;
        int end = n-1;

        while(start+1 < end)
        {
            int mid = (start+end)/2; 
            if(A[mid] == target) 
                return mid;
            else if (target < A[mid])
                end = mid;
            else
                start = mid;
        }

        return end;
    }

};
