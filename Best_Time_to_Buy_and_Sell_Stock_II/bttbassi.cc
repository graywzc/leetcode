class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int maxp = 0;         
        int prevp = INT_MAX;
        for(int i = 0; i < prices.size(); i++)
        {
            int p = prices[i]; 
            if(p > prevp)
                maxp += (p-prevp);
            prevp = p;
        }

        return maxp;
    }
};
