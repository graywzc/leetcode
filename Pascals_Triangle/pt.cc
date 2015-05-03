class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;       
        for(int i = 0; i < numRows; i++)
        {
            vector<int> temp;
            temp.push_back(1);
            res.push_back(temp);     
        }

        for(int i = 1; i < numRows; i++)
        {
            res[i].push_back(1); 
            for(int j = i+1; j < numRows; j++)
            {
                int size = res[j-1].size();
                res[j].push_back(res[j-1][size-1]+res[j-1][size-2]); 
            }
        }

        return res;
    }
};
