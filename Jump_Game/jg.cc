class Solution {
public:
    bool canJump(int A[], int n) {
        int i = 0;
        while(i < n)        
        {
            if(i == n-1)
                return true;

            if(A[i] == 0)
            {
                int j = i+1; 
                while(j < n && A[j] == 0)
                {
                    j++; 
                }
                
                if(j == n)
                {
                    int k = i - 1; 
                    while(k>=0)
                    {
                        if(A[k]>=(j-k-1))
                            return true;
                        k--; 
                    }
                    return false;
                }
                else
                {
                    int k = i - 1; 
                    while(k>=0)
                    {
                        if(A[k]>=(j-k))
                        {
                            i = j; 
                            break;
                        }
                        k--; 
                    }
                    if(k>=0)
                        continue;
                    else
                        return false;
                }
            }
            i++; 
        }
    }
};
