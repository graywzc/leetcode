class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i = 0;
        while(i < n)        
        {
            if((i+1)<n && A[i] == A[i+1])  
            {
                int j = i+2; 
                while(j<n && A[j] == A[i])
                    j++;
                if(j>(i+2))
                {
                    if(j<n) 
                        memmove(A+i+2, A+j, sizeof(int)*(n-j));
                    n-=(j-i-2);
                    i = i+2;
                }
                else
                    i = j;
            }
            else
                i++;
        }

        return n;
    }
};
