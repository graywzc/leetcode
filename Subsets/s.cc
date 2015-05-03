class Solution {
public:
    void ss(vector<vector<int> >& res, const vector<int> &S, vector<int>& temp, int i)
    {
        if(S.size() == i) 
        {
            res.push_back(temp);     
        }
        else
        {
            temp.push_back(S[i]); 
            ss(res, S, temp, i+1);  
            temp.pop_back();
            ss(res, S, temp, i+1);
        }
    }

    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        sort(S.begin(), S.end());        
        
        vector<int> temp;
        ss(res, S, temp, 0);

        return res;
    }
};
