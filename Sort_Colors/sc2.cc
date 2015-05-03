// quick sort
#include <stdio.h>
class Solution {
public:

    static void quick_sort(int A[], int start, int end)
    {
        if(start>=end) 
            return;
        int pivot = A[end];
        int j = start;
        int temp;
        for(int i = start; i < end; i++ )
        {
            if(A[i] < pivot)
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                j++;
            }
        }
        temp = A[end];
        A[end] = A[j];
        A[j] = temp;
        quick_sort(A, start, j-1);
        quick_sort(A, j+1, end);
    }

    static void sortColors(int A[], int n) {
        quick_sort(A, 0, n-1);       
    }
};

int main()
{
    int A[] = {1,2,0};
    Solution::sortColors(A, 3);
    for(int i = 0; i < 3; i++)
        printf("%d\n", A[i]);

}
