class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i = 0;        
        while(i < n)
        {
            int j = i + 1;  
            while(j < n && A[i] == A[j])
                j++;

            if(j>(i+1))
            {
                if(j < n)
                    memmove(A+i+1, A+j, sizeof(int)*(n-j));
                n -= (j-i-1);
            }

            i++;
        }

        return n;
    }
};
