// recursive solution , too slow

class Solution {
public:
    int numDistinct(const string & S, int starts, int ends, const string & T, int startt, int endt)
    {
        if(startt > endt) 
            return 1;
        else if(starts > ends)
            return 0;
        else
        {
            int count = 0;
            char c = T[startt];
            for(int i = starts; i <= ends; i++)
            {
                if(S[i] == c)   
                {
                    count += numDistinct(S, i+1, ends, T, startt+1, endt); 
                }
            }

            return count;
        }
    }
    int numDistinct(string S, string T) {
        int ss = S.size();
        int st = T.size();
        if(st == 0)
            return 1;
        if(ss == 0)
            return 0;

        return numDistinct(S, 0, ss-1, T, 0, st-1);
    }
};
