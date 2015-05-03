// merge sort

class Solution {
public:

    void merge_sort(int A[], int start, int end)
    {
        if(start ==  end) 
            return;
        int mid = (start+end)/2;
        merge_sort(A, start, mid);
        merge_sort(A, mid+1, end);
        int *temp = new int[end-start+1];
        int i = start, j = mid+1, k = 0;
        while(i <= mid && j <= end)
        {
            if(A[i]<A[j])
            {
                temp[k++] = A[i];
                i++;
            }
            else
            {
                temp[k++] = A[j];
                j++;
            }
        }
        if(i>mid)
            memcpy(temp+k, A+j, sizeof(int)*(end-j+1)); 
        else
            memcpy(temp+k, A+i, sizeof(int)*(mid-i+1));
        memcpy(A+start, temp, sizeof(int)*(end-start+1));

        delete [] temp;
    }
    
    void sortColors(int A[], int n) {
    
        merge_sort(A, 0, n-1);
        
        
    }
};
