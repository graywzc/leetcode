class Solution {
public:
    
    double median_search(int A[], int m, int B[], int n, int left, int right)
    {
        if (left>right)
            return median_search(B,n,A,m,max(0,(n-m)/2),min(n-1,(m+n)/2));
        int i, j;
        i = (left+right)/2;
        j = (m+n)/2 - 1 - i;
        if(( j==-1 || A[i]>=B[j] )  && ( j==(n-1) || A[i]<=B[j+1] ))
            return A[i];
        else if ((j==-1 || A[i]>=B[j]) && (A[i]>B[j+1]))
            return median_search(A,m,B,n,left,i-1);
        else 
            return median_search(A,m,B,n,i+1,right);
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m==0)
        {
            if(n%2)
                return B[n/2];
            else
                return 0.5*(B[n/2-1]+B[n/2]);
        }
        
        if (n==0)
        {
            if(m%2)
                return A[m/2];
            else
                return 0.5*(A[m/2-1]+A[m/2]);
        }
        
        if ((m+n)%2)
            return median_search(A,m,B,n,max(0,(m-n)/2),min(m-1,(m+n)/2));
        else
        {
            int m1,m2;
            if(A[0]>B[0])
                m1 = median_search(A,m,B+1,n-1,max(0,(m-n+1)/2),min(m-1,(m+n-1)/2));
            else
                m1 = median_search(A+1,m-1,B,n,max(0,(m-1-n)/2),min(m-2,(m+n-1)/2));
            if (A[m-1]>B[n-1])
                m2 = median_search(A,m-1,B,n,max(0,(m-1-n)/2),min(m-2,(m-1+n)/2));
            else
                m2 = median_search(A,m,B,n-1,max(0,(m-n-1)/2),min(m-1,(m+n-1)/2));
            
            return 0.5*(m1+m2);
        }
        
        
            
    }
};
