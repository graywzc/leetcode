class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(n == 0)            
            return 1;

        sort(A, A+n);
        
        int i = 0;

        while(i < n && A[i] <= 0)
            i++;

        if(i == n)
            return 1;

        int idx = 1;
        while(i < n)
        {
            if(A[i]!=idx) 
                return idx;
            else    
            {
                idx++;
                int j = i+1;
                while(j < n && A[j] == A[i])
                    j++;
                i = j;
            }
        }

        return idx;
    }
};
