class Solution {
public:

    void recurSubsetsWithDup(vector<vector<int> > &res, vector<int> &temp, int i, const vector<int> &S)
    {
        if(i == S.size()) 
        {
            res.push_back(temp);  
            return;
        }
        else
        {
            int j = i+1; 
            while(j < S.size() && S[j] == S[i])
                j++; 
            int count = j-i;

            for(int l = 0; l <= count; l++)
            {
                recurSubsetsWithDup(res, temp, j, S);
                temp.push_back(S[i]);
            }
            for(int l = 0; l <= count; l++)
                temp.pop_back();
            return;
        }
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;
        if(0 == S.size())
        {
            res.push_back(vector<int>()); 
            return res;
        }
        sort(S.begin(), S.end());
         
        vector<int> temp;
        recurSubsetsWithDup(res, temp, 0, S);

        return res;

    }
};
