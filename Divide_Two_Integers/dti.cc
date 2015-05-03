// hit "time limit exceeded"

class Solution {
public:
    int divide(int dividend, int divisor) {
        assert(divisor != 0);
        if(dividend == 0) 
            return 0;

        bool neg = (dividend>0) == (divisor<0);
        if(dividend<0)        
            dividend = -dividend;
        if(divisor<0)
            divisor = -divisor;

        int res = 0;
        while(dividend>divisor)
        {
            res++;
            dividend-=divisor;
        }

        if(neg)
            res = -res;
        return res;
    }
};
