class Solution {
public:

    int maxP(const vector<int> &prices, int start)
    {
        int lp = INT_MAX; 
        int mp = 0;

        int i = start; 
        while(i < prices.size())
        {
            if(prices[i] < lp)
                lp = prices[i];
            else if((prices[i] - lp)>mp)
                mp = prices[i]-lp;

            i++; 
        }

        return mp;
    }

    int maxProfit(vector<int> &prices) {
        int lp = INT_MAX;    
        int mp1 = 0;
        int mp_total = 0;

        int i = 0;
        while(i < prices.size())
        {
            if(prices[i] < lp)
                lp = prices[i];
            else if((prices[i] - lp) > mp1)
            {
                mp1 = prices[i] - lp;
                int mp2 = maxP(prices, i+1);
                if((mp1+mp2)>mp_total)
                    mp_total = mp1+mp2;
            }

            i++; 
        }

        return mp_total;
    }
};
