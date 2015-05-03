// Implement the KMP algorithm, refer to chapter 32.4 of CLRS
//
#include <stdio.h>
#include <string.h>

class Solution {
public:

    static char *strStr(char *haystack, char *needle) {
        int m = strlen(needle); 
        int n = strlen(haystack);

        if(m == 0)
            return haystack;
        if(n == 0)
            return NULL;

        int *pi = new int[m];
        
        // computer prefix function
        pi[0] = -1;
        int k = -1;
        for(int i = 1; i < m; i++)
        {
            while(k>=0 && needle[k+1] != needle[i])
                k = pi[k];
            if(needle[k+1] == needle[i])
                k += 1;
            pi[i] = k;
        }

        // kmp matching
        int q = -1;
        for(int i = 0; i < n; i++) 
        {
            while(q >= 0 && needle[q+1] != haystack[i])      
                q = pi[q];
            if (needle[q+1] == haystack[i])
                q += 1;
            if (q == m-1)
                return haystack+i-m+1;
        }
        
        delete [] pi;

        return NULL;
        
    }
};

int main(int argc, char* argv[])
{
    char *h = "bbabbaababbaabbbbababbabbbabaaabbabaabbaabbaaabbaaabaaabbbabbabbaabbbbbbaabaabbabbabbaaabaabababbbaaabbaaaaababbbbabbbbbbbaaaabbbbbaaaaabbbabababababbbaababbbabaabbabbbaaabababbba";
    //char *h = "aaa";
    char *n = "abbbbbaababbaaabaaaaaaabaaabbaa";
    //char *n = "a";
    char *s = Solution::strStr(h,n);
    if(s == NULL)
        printf("not match\n");
    else
        printf("%s\n", s);
    return 0;
}
