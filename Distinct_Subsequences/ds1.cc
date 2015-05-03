// dynamic programming solution

class Solution {
public:
#define nd(i,j) nd[(i)*ss + (j)]
    int numDistinct(string S, string T) {
        int ss = S.size();
        int st = T.size();
        if(st == 0)
            return 1;
        if(ss == 0)
            return 0;

        int *nd = new int[(ss+1)*(st+1)]; 
        
        for(int i = 0; i <= ss; i++)
            nd(0,i) = 1; 
        for(int i = 1; i <= st; i++)
            nd(i,i-1) = 0; 

        for(int i = 1; i <= st; i++)
            for(int j = i; j <= ss; j++) 
                if(T[i-1] == S[j-1])
                    nd(i,j) = nd(i-1, j-1) + nd(i, j-1); 
                else
                    nd(i,j) = nd(i, j-1);
                    
        return nd(st, ss);
    }
};
