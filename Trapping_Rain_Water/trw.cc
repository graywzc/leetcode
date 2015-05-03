// my solution

class Solution {
public:
    int trap(int A[], int n) {
        int total = 0;
        int left_max = INT_MIN;
        for(int i = 0; i < n; i ++)    
        {

            if(left_max > A[i])
            {
                int right_max = INT_MIN;
                for(int j = i+1; j < n; j++) 
                {
                    if(A[j]>right_max) 
                        right_max = A[j];
                }
                if(right_max>A[i])
                {
                    total += min(left_max - A[i], right_max - A[i]); 
                }
            }
            if(A[i] > left_max) 
                left_max = A[i];
        }

        return total;
    }
};
