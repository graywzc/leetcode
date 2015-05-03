// heap sort

#define parent(i)  (((i)-1)/2)
#define left(i)  (2*(i)+1)
#define right(i)  (2*(i)+2)

void heapify(int A[], int i, int n)
{
    int left = left(i);
    int max = A[i];
    int maxi = i;
    if(left < n && max < A[left])
    {
        max = A[left];
        maxi = left;
    }
    int right = right(i);
    if(right < n && max < A[right])
    {
        max = A[right];
        maxi = right;
    }
    if(maxi != i)
    {
        A[maxi] = A[i];
        A[i] = max; 
        heapify(A, maxi, n);
    }
}

void heap_sort(int A[], int n)
{

    int i = (n-2)/2; 
    while(i>=0)
    {
        heapify(A,i,n);
        i--;  
    }

    i = n-1; 
    while(i > 0)
    {
        int temp = A[i];  
        A[i] = A[0];
        A[0] = temp;

        heapify(A, 0, i);
        i--;
    }
}

void sortColors(int A[], int n) {

   heap_sort(A, n); 

}
