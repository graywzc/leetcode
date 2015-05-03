class Solution {
public:

    bool isPalin(const string &s, int i, int j)
    {
        if(i==j) 
            return true;
        else
        {
            int k = i, l = j;
            while(k<l)
            {
                if(s[k]!=s[l])
                    return false;
                k++; 
                l--;
            }
            return true;
        }
    }
    void partition(const string &s, int i, vector<vector<string>>& res, vector<string>& temp)
    {
        if(i == s.size()) 
        {
            res.push_back(temp); 
            return;
        }
        else
        {
            int j = i;
            while(j<s.size())
            {
                if(isPalin(s,i,j))
                {
                    string local(s, i, j-i+1);         
                    temp.push_back(local);
                    partition(s, j+1, res, temp);
                    temp.pop_back();
                }
                j++; 
            }
            return
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;       
        if(s.size()==0) return res;
        vector<string> temp;
        partition(s, 0, res, temp)
        return res;
    }
};
