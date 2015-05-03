#include <stdio.h>
#include <assert.h>

class Solution {
public:
    static int divide(int dividend, int divisor) {
        assert(divisor != 0);
        if(dividend == 0) 
            return 0;

        bool neg = (dividend>0) == (divisor<0);
        unsigned int dvd = (dividend>0)?dividend:-dividend;
        unsigned int dvs = (divisor>0)?divisor:-divisor;

        unsigned int m = 1;
        while(dvs < dvd)
        {
            m = m<<1; 
            dvs = dvs<<1;
        }

        if(dvs > dvd)
        {
            m = m>>1; 
            dvs = dvs>>1;
        }

        unsigned int res = 0;
        while(m>0)         
        {
            if(dvd>=dvs)
            {
                res += m;
                dvd -= dvs;
            }
            m = m>>1;
            dvs = dvs>>1;
        }

        return neg?-res:res;
    }
};

int main()
{
    int a = 2147483647;
    int b = 1;
    int c = Solution::divide(a,b);
    printf("c = %d\n", c);
    printf("c = %d\n", a/b);
}
