class Solution {
public:
    double pow(double x, int n) {
        if (0==n)       
            return 1; 
        bool isNeg = false;
        if (n<0)
        {
            isNeg = true;
            n = -n;
        }

        double res = 1;
        while(n>0)
        {
            
            if(n%2)
                res *= x;
            n = n>>1;
            x = x*x;
        }

        if(isNeg)
            res = 1/res;
        
        return res;
            
    }
};
