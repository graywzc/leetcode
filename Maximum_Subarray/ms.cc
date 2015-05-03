// 1-d dp solution
class Solution {
public:
    int maxSubArray(int A[], int n) {
        int global_max = INT_MIN;        
        int local_max = 0;
        for(int i = 0; i < n; i++)
        {
            local_max+=A[i]; 
            if(local_max > global_max)
                global_max = local_max;
            if(local_max < 0)
                local_max = 0;
        }

        return global_max;
    }
};
