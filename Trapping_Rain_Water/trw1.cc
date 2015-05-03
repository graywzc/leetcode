// better solution
class Solution {
public:
    int trap(int A[], int n) {
        int total = 0;

        if(n == 0)
            return 0;
        int *left_max = new int[n];
        int *right_max = new int[n];

        left_max[0] = INT_MIN;
        for(int i = 1; i < n; i++ )
            left_max[i] = max(left_max[i-1], A[i-1]); 
        right_max[n-1] = INT_MIN;
        for(int i = n-2; i >= 0; i--)
            right_max[i] = max(right_max[i+1], A[i+1]);
        for(int i = 1; i < n-1; i++)
        {
            if(left_max[i] > A[i] && right_max[i] > A[i]) 
                total += (min(left_max[i], right_max[i]) - A[i]);
        }

        delete [] left_max;
        delete [] right_max;
        return total;
    }
};
