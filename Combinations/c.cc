class Solution {
public:
    void comb(vector<vector<int> >& res, vector<int>& temp, int n, int k, int i)
    {
        if (k == 0 || (n-i+1)==k)  
        {
            if(k == 0)
                res.push_back(temp); 
            else
            {
                for(int j = i; j <= n; j++) 
                    temp.push_back(j);
                res.push_back(temp);
                for(int j = i; j <= n; j++) 
                    temp.pop_back();
            }
            return;
        }
        else
        {
            temp.push_back(i); 
            comb(res, temp, n, k-1, i+1);
            temp.pop_back();

            comb(res, temp, n, k, i+1);

            return;
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;        
        vector<int> temp; 
        if(k>n || n<1 || k<0)
            return res;
        comb(res, temp, n, k, 1);

        return res;
    }
};
