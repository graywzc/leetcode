class Solution {
public:
    bool isValid(int row1, int col1, int row2, int col2)
    {
        if(col1 == col2)
            return false;
        if(abs(row1 - row2) == abs(col1 - col2))
            return false;

        return true;
    }

    void solveNQueens(int n, int i, vector<vector<string> > &res, vector<int> &pos)
    {
        if(i == n) 
        {
            vector<string> ans;
            for(int j = 0; j < n; j++) 
            {
                string temp(n,'.');
                temp[pos[j]] = 'Q';
                ans.push_back(temp);
            }
            res.push_back(ans);
            return;
        }
        else
        {
            for(int j = 0; j < n; j++) 
            {
                bool flag = true;
                for(int k = 0; k < i; k++) 
                {
                    if(!isValid(k,pos[k],i,j)) 
                    {
                        flag = false; 
                        break;
                    }
                }
                if(flag)
                {
                    pos[i] = j;
                    solveNQueens(n, i+1, res, pos);
                }
                else
                    continue; 
            }

            return;
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        if(n==0)
            return res;

        if(n==1) 
        {
            res.push_back(vector<string>(1, string("Q"))); 
            return res; 
        }

        vector<int> pos(n);               
        solveNQueens(n, 0, res, pos);
        return res;
    }
};
