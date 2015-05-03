
// optimized version
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxl = -1;
        int maxs = 0;
        int bin[256];
        memset(bin,-1,sizeof(int)*256);
        
        int visit = 0;
        int currentl = 0;
        int currents = 0;
        while(visit < s.length())
        {
            if(bin[s[visit]] >=0)
            {
                if(currentl > maxl)
                {
                    maxs = currents;
                    maxl = currentl;
                }
                while(currents<=bin[s[visit]])
                {
                    bin[s[currents]] = -1;
                    currents++;
                    currentl--;
                }
                bin[s[visit]] = visit;
                visit++;
                currentl++;
            }
            else
            {
                bin[s[visit]] = visit;
                visit++;
                currentl++;
            }
            
        }
        if (currentl > maxl)
            return currentl;
        else
            return maxl;
    }
};
