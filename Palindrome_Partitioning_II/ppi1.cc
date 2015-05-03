// still hit "Time Limit Exceed"

class Solution {
public:
    bool isPalin(const string& s, int i, int j)
    {
        while(i < j)
        {
            if(s[i]!=s[j]) 
                return false;
            i++;
            j--;
        }
        return true;
    }

    void minCut(const string& s, int *dp, int i)
    {
        int size = s.size();
        int j = size-i;
        if(isPalin(s, j, size-1))
        {
            dp[i] = 0; 
            return;
        }
        else
        {
            int k = j; 
            while(k < (size-1))
            {
                if(isPalin(s,j,k))
                {
                    if(dp[size-1-k] == INT_MAX)
                        minCut(s, dp, size-1-k);
                    dp[i] = min(dp[i], 1 + dp[size-1-k]); 
                }
                k++;
            }
        }
    }

    int minCut(string s) {
        if(s.size() <= 1)
            return 0;
        int size = s.size();
        int *dp = new int[size+1];        
        int i = 0;
        while(i <= size) 
        {
            dp[i] = INT_MAX;
            i++; 
        }
        minCut(s, dp, size);

        int res = dp[size];
        delete [] dp;
        return res;

    }
};
