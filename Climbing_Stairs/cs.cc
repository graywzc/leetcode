class Solution {
public:
    int climbStairs(int n) {
        int past1 = 0;
        int past0 = 1;
        int current;
        for(int i=1; i<=n; i++)        
        {
            current = past1+past0; 
            past1 = past0;
            past0 = current;
        }

        return current;
    }
};
