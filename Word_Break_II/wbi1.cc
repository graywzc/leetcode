// pure recursive solution, hit "time limit exceed"
class Solution {
public:

    void wordBreak(vector<string> &res, const string& s, const unordered_set<string> &dict, string & temp, int cur)
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
                if(dict.find(subs)!=dict.end())
                {
                    temp+=subs; 
                    temp+=" ";
                    wordBreak(res, s, dict, temp, i+1);
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
        wordBreak(res, s, dict, temp, 0); 

        return res;
    }
};
