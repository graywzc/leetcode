// dp like algorithm, not the best solution 
class Solution {
public:
    int jump(int A[], int n) {
        if(n<=1)
            return 0;
        int i = n-2;
        A[n-1] = 0;
        while(i>=0)
        {
            int j = i+1;
            int min = INT_MAX;
            while(j<=n-1 && (j-i)<=A[i])
            {
                if(A[j] != -1) 
                    if(A[j] < min)
                        min = A[j];
                ++j;
            }
            if(min == INT_MAX)
                A[i] = -1;
            else
                A[i] = min+1;
            i--;  
        }

        return A[0];
    }
};
