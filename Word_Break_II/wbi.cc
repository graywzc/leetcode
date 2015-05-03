// memory limit exceeded
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;        
        if(s.size() == 0)
            return res;
        if(dict.size() == 0)
            return res;

        int ss = s.size();

        vector<vector<string> > wb(ss, vector<string>());
        for(int i = 0; i < ss; i++)
        {
            if(dict.find(s.substr(0, i+1)) != dict.end())
                wb[i].push_back(s.substr(0,i+1));
            for(int j = i; j > 0; j--) 
            {
                
                string subs = s.substr(j, i-j+1);
                if(dict.find(subs) != dict.end()) 
                {
                    for(string pre: wb[j-1])     
                    {
                        string temp(pre);
                        temp+=" "; 
                        temp+=subs;
                        wb[i].push_back(temp);
                    }
                }
            }
        }

        return wb[ss-1];     
    }
};
