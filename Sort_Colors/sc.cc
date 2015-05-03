class Solution {
public:
    void sortColors(int A[], int n) {
        int nRed=0,nYellow=0,nBlue=0;    
        int i = 0;
        while(i<n)
        {
            if(A[i]==0)
                nRed++;
            if(A[i]==1)
                nYellow++;
            if(A[i]==2)
                nBlue++;
            i++;
        }
        i = 0;
        while(i < nRed)
        {
            A[i] = 0;
            i++; 
        }
        while(i < nYellow + nRed)
        {
            A[i] = 1;
            i++;
        }
        while(i < nBlue + nYellow + nRed) 
        {
            A[i] = 2;
            i++;
        }

    }
};
