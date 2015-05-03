// recursive solution
#include <stdio.h>
#include <string>
using namespace std;

class Solution {
public:
    
    static int minDistance(const char *pw1, int size1, const char* pw2, int size2)
    {
        if(size1 == 0)
            return size2;
        if(size2 == 0)
            return size1;
        int min = 1 + minDistance(pw1, size1, pw2+1, size2-1);
        int d1 = 1 + minDistance(pw1+1, size1-1, pw2, size2);
        if(d1 < min)
            min = d1;
        d1 = minDistance(pw1+1, size1-1, pw2+1, size2-1) + ((*pw1==*pw2)?0:1);
        if(d1 < min)
            min = d1;

        return min;
    }

    static int minDistance(string word1, string word2) {
        const char *pw1 = word1.c_str();    
        const char *pw2 = word2.c_str();
        int size1 = word1.size();
        int size2 = word2.size();

        return minDistance(pw1, size1, pw2, size2);
    }
};

int main()
{
    string s1("dinitrophenylhydrazine");
    string s2("acetylphenylhydrazine");
    int d = Solution::minDistance(s1, s2);
    printf("%d\n",d);
}
