class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if(n==0)
            return; 
        if(m==0)
            memcpy(A,B,sizeof(int)*n);
        int i = 0;
        int j = 0;
        int j0 = 0;
        while(i < m && j < n)
        {
            if(A[i]>B[j])
            {
                j++;
            }
            else
            {
                if(j>j0)
                {
                    memmove(A+i+j-j0, A+i, sizeof(int)*(m-i));
                    memcpy(A+i,B+j0,sizeof(int)*(j-j0));
                }
                i+=1+j-j0;
                m+=j-j0;
                j0 = j;
            }
        }

        if(i==m) 
            memcpy(A+i, B+j0, sizeof(int)*(n-j0));
        else 
        {
            memmove(A+i+j-j0, A+i, sizeof(int)*(m-i));
            memcpy(A+i, B+j0, sizeof(int)*(j-j0));
        }
            
    }
};
