class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0)
            return 0;
        int *nd = new int[s.size()+1];        

        if(s[0] == '0')
            return 0;
        nd[0] = 1;
        nd[1] = 1;
        int i = 2;
        while(i <= s.size()) 
        {
            int j = i-1;
            if(s[j] == '0')
            {
                if(s[j-1]!='1' && s[j-1]!='2') 
                    return 0;
                else
                    nd[i] = nd[i-2];
            }
            else
            {
                if(s[j]>='1' && s[j]<='6')  
                {
                    if(s[j-1] == '1' || s[j-1] == '2') 
                        nd[i] = nd[i-1] + nd[i-2];
                    else
                        nd[i] = nd[i-1];
                }
                else
                {
                    if(s[j-1] == '1') 
                        nd[i] = nd[i-1] + nd[i-2];
                    else
                        nd[i] = nd[i-1];
                }
            }
            i++; 
        }

        return nd[s.size()];
        
    }
};
