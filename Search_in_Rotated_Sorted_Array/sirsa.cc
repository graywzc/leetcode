class Solution {
public:
    
    int bs(int A[], int start, int end, int target)
    {
        if(start > end)
            return -1;
        if(start == end)
        {
            if(target == A[start])
                return start;
            else    
                return -1;
        }

        int mid = (start+end)/2; 
        if(A[start] < A[end])
        {
            if(target == A[mid])
                return mid;
            else if (target > A[mid])
                return bs(A, mid+1, end, target);
            else
                return bs(A, start, mid-1, target);
        }
        else
        {
            if(target == A[mid])
                return mid;
            if(target == A[start])
                return start;
            if(target == A[end])
                return end;

            if(A[mid] >= A[start]) 
            {
                if(target < A[mid] && target > A[start])
                    return bs(A, start+1, mid-1, target);
                else
                    return bs(A, mid+1, end-1, target);
            }
            else
            {
                if(target > A[mid] && target < A[end])   
                    return bs(A, mid+1, end-1, target);
                else
                    return bs(A, start+1, mid-1, target);
            }
        }
          
    }
    int search(int A[], int n, int target) {
        return bs(A, 0, n-1, target);             
    }
};
