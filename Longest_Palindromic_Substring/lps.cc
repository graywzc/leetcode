class Solution {
public:
    string convertString(const string& s)
    {
        int length = s.length();
        string res = "^#";
        for(int i = 0; i < length; i++)
        {
            res+=s[i];
            res+="#";
        }
        res+="$";
        return res;
    }
    string longestPalindrome(string s) {
        if (s.length() == 0)
            return s;
        string t = convertString(s);
        int c = 0, r = 0;
        int n = t.length();
        int* p = new int[n];
        memset(p,0,sizeof(int)*n);
        for(int i = 1; i < n-1; i++)
        {
            int mirror_i = 2*c-i;
            p[i] = (r>i)?min(p[mirror_i],r-i):0;
            
            while(t[i+1+p[i]] == t[i-1-p[i]])
                p[i]++;
            
            if(i+p[i]>r)
            {
                c = i;
                r = i + p[i];
            }
        }
        
        int maxl = 0;
        int maxi = 0;
        for(int i = 1; i < n-1; i++)
        {
            if (p[i] > maxl)
            {
                maxl = p[i];
                maxi = i;
            }
        }
        string res = "";
        for(int i = maxi - maxl + 1; i < maxi + maxl; i+=2)
        {
            res+=t[i];
        }
        
        return res;
        
    }
};
