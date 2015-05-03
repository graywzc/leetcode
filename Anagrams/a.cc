#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    
    static string sortStr(const string& s)
    {
        vector<int> bn(26,0);        
        for(int i = 0; i < s.size(); i++)
        {
            bn[(s[i] - 'a')] ++;
        }
        string res;
        for(int i = 0; i < bn.size(); i++)
        {
            for(int j = 0; j < bn[i]; j++) 
            {
                res.push_back('a'+i); 
            }
        }
        return res;
    }

    static vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<int> > ht;   
        unordered_map<string, vector<int> >::iterator it;   

        vector<string> res;

        for(int i = 0; i < strs.size(); i++)
        {
            it = ht.find(sortStr(strs[i]));      
            if(it!=ht.end())
                it->second.push_back(i);
            else
                ht[sortStr(strs[i])].push_back(i);
        }
        
        for(it = ht.begin(); it!=ht.end(); it++)
        {
            if(it->second.size() > 1 ) 
            {
                for(int i = 0; i < it->second.size(); i++ ) 
                    res.push_back(strs[it->second[i]]);
            }
        }

        return res;
    }
};

int main()
{
    vector<string> strs;    
    strs.push_back("");
    strs.push_back("");
    vector<string> res = Solution::anagrams(strs);

    for(int i = 0; i < res.size(); i++)
        printf("%s\n", res[i].c_str());
}
