// my accepted code
class Solution {
public:
    bool match(const char *s, int i, const char *p, int j)
    {
        if(s[i] == '\0' && p[j] == '\0')
            return true;
        else if (s[i] == '\0')
        {
            if(p[j+1]=='*')
                return match(s,i,p,j+2);
            else
                return false;
        }
        else if (p[j] == '\0')
            return false;
        else
        {
            while(p[j+1] != '*') // only when p[j+1]=='*', we need some special treatment
            {
                if(s[i] == p[j] || p[j] == '.')
                {
                    return match(s,i+1,p,j+1);
                }
                else 
                    return false;
            }
            // there two scenarios, p[j]=='.' or p[j] is other char
            if(p[j] == '.')
            {
                while(1)
                { 
                    if(match(s,i,p,j+2))
                        return true;
                    if(s[i]!='\0')
                        i++;
                    else
                        return false;
                }
            }
            else
            {
                while(1)
                {
                    if(match(s,i,p,j+2))
                        return true;
                    if(s[i]==p[j])
                        i++;
                    else
                        return false;
                }
            }
        }
    }
    
    bool isMatch(const char *s, const char *p) {
        return match(s,0,p,0);
    }
};
