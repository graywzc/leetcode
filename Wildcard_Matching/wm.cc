#include <stdio.h>
// my recursive version, too slow

class Solution {
public:
    static bool isMatch(const char *s, const char *p) {
        if (s == NULL) return false;
        if (p == NULL) return false;
        
        if(*s == '\0' && *p == '\0')
            return true;
        else if( *p == '\0')
        {
            return false;
        }
        else
        {
            if(*p != '*' && *p!='?')  
            {
                if(*s == *p)
                    return isMatch(s+1,p+1);
                else
                    return false;
            }
            else if(*p == '?')
                return *s!='\0' && isMatch(s+1,p+1);
            else
            {

                if(*(p+1) == '*')
                    return isMatch(s,p+1);
                
                if(isMatch(s,p+1))
                    return true;
                while(*s!='\0')
                {
                    s++; 
                    if(isMatch(s,p+1))
                        return true;
                }

                return isMatch(s,p+1);

            }
        }

    }

   static bool isMatch1(const char *s, const char *p) {
     // Start typing your C/C++ solution below
        // DO NOT write int main() function
         
        const char* star=NULL;
        const char* ss=s; 
        while (*s){
            if ((*p=='?')||(*p==*s)){s++;p++;continue;}
            if (*p=='*'){star=p++; ss=s;continue;}
            if (star){ p = star+1; s=++ss;continue;}
            return false;
        }
        while (*p=='*'){p++;}
        return !*p;
        
    }
};

int main()
{

    //char *s = "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba";
    const char *s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    //char *p = "a*******b";
    const char *p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    if(Solution::isMatch1(s,p))
        printf("match\n");
    else
        printf("mismatch\n");
}

