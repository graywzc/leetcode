// recursive solution
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
class Solution {
public:

    static bool isScramble(string s1, int start1, int end1, string s2, int start2, int end2)
    {
        int tbl[128];        
        memset(tbl, 0, sizeof(int)*128);
        for(int i = start1; i <= end1; i++)
            tbl[s1[i]] ++;

        for(int i = start2; i <= end2 ; i++)
        {
            tbl[s2[i]] --; 
            if(tbl[s2[i]]<0)
                return false;
        }
            
        if(start1 == end1)
            return true;
        for(int i = start1; i < end1; i++)
        {
            if(isScramble(s1, start1, i, s2, start2, i-start1+start2) && isScramble(s1, i+1, end1, s2, i-start1+start2+1, end2)) 
                return true;
            if(isScramble(s1, start1, i, s2, end2-i+start1, end2) && isScramble(s1, i+1, end1, s2, start2, end2-i+start1-1) )
                return true;
        }

        return false;
    }

    
    static bool isScramble(string s1, string s2) {
        
        return isScramble(s1, 0, s1.size()-1, s2, 0, s2.size()-1);

    }
};

int main()
{
    string s1("abcd");
    string s2("bdac");

    bool res = Solution::isScramble(s1, s2);

    if(res)
        printf("yes\n");
    else
        printf("no\n");
        

}
