// skip some unnecessary recursion
class Solution {
public:

    void wordBreak(vector<string> &res, const string& s, const unordered_set<string> &dict, string & temp, int cur,vector<bool> & possible)
    {
        if(cur == s.size()) 
        {
            temp.pop_back();
            res.push_back(temp);
            temp+=" ";
            return;
        }
        else
        {
            for(int i = cur; i < s.size(); i++) 
            {
                string temp1 = temp;
                string subs = s.substr(cur, i-cur+1);
                if(dict.find(subs)!=dict.end()&& possible[i+1])
                {
                    int before = res.size();
                    temp+=subs; 
                    temp+=" ";
                    wordBreak(res, s, dict, temp, i+1, possible);

                    if(res.size() == before)
                        possible[i+1] = false;
                    temp = temp1;
                }
            }
            return;
        }
    }
    
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;        
        if(s.size()==0)
            return res;
        if(dict.size() == 0)
            return res;
        
        string temp;
        vector<bool> possible(s.size()+1, true);
        wordBreak(res, s, dict, temp, 0, possible); 

        return res;
    }
};
