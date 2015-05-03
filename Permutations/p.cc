class Solution {
public:

    void perm(vector<vector<int> >& res, vector<int>& num, int i)
    {
        if(i == num.size())
        {
            res.push_back(num);  
            return;
        }
        for(int j = i; j < num.size(); j++)
        {
            int temp = num[j]; 
            num[j] = num[i];
            num[i] = temp;
            perm(res, num, i+1);
            num[i] = num[j];
            num[j] = temp;
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        perm(res, num, 0);
        return res;
    }
};
