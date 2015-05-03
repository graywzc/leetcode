class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxp = 0;        
        int lp = INT_MAX;
        for(int i = 0; i < prices.size(); i++)
        {
            int p = prices[i];
            if(p < lp)
                lp = p;
            else if(p > lp)
            {
                int profit = p - lp; 
                if(profit > maxp)
                    maxp = profit;
            }
        }

        return maxp;
    }
};
