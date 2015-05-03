// divide and conquer solution
class Solution {
public:
    
    int maxsa(int A[], int start, int end)
    {
        if(start == end) 
            return A[start];
        else
        {
            int mid = (start+end)/2; 
            int left_max = maxsa(A, start, mid);
            int right_max = maxsa(A, mid+1, end);
            
        }
    }
    int maxSubArray(int A[], int n) {
                
    }
};
