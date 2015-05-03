// also use DP on checking palidrom
class Solution {
public:
    int minCut(string s) {
        if(s.size() <= 1)    
            return 0;
        int size = s.size();
        vector<int> mc(size);
        vector<vector<bool> > isPal(size, vector<bool>(size,false));

        for(int i = size-1; i >= 0; i--)
            for(int j = i; j < size; j++)
                isPal[i][j] = (s[i]==s[j]) && ((j-i)<=2||isPal[i+1][j-1]);     

        for(int i = 0; i < size; i++)
        {
            if(isPal[0][i]) 
                mc[i] = 0;
            else
            {
                mc[i] = i;
                for(int j = 0; j < i; j++) 
                {
                    if(isPal[j+1][i]) 
                        mc[i] = min(mc[i], 1+mc[j]);
                }
            }
        }

        return mc[size-1];

    }
};
