#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    static int str2int(const string& s)
    {
        int res = 0; 
        int i = 0;
        while(i < s.size())
        {
            res = res*10 + s[i] - '0'; 
            i++; 
        }
        return res;
    }

    static void restoreIpAddresses(const string& s, vector<string> &res, string& temp, int i, int count)
    {
        if(i == s.size()) 
        {
            if(count == 4) 
            {
                res.push_back(temp); 
                res.back().pop_back();
                return;
            }
            else
                return;
        }
        else
        {
            if(count == 4) 
                return;
            else if(s[i] == '0')
            {
                temp+="0.";     
                restoreIpAddresses(s, res, temp, i+1, count+1);
                temp.pop_back();
                temp.pop_back();
                return;
            }
            else
            {
                temp+=s[i]; 
                temp+='.';
                restoreIpAddresses(s, res, temp,i+1, count+1);
                temp.pop_back();
                if((i+1)<s.size())
                {
                    temp+=s[i+1]; 
                    temp+='.';
                    restoreIpAddresses(s, res, temp, i+2, count+1);
                    temp.pop_back();
                }
                if((i+2)<s.size() && str2int(s.substr(i,3)) <= 255)
                {
                    temp+=s[i+2]; 
                    temp+='.';
                    restoreIpAddresses(s, res, temp, i+3, count+1);
                    temp.pop_back();
                }
                while(temp.size()>0 && temp.back()!='.')
                {
                    temp.pop_back();
                }
                return;
            }
        }
    }

    static vector<string> restoreIpAddresses(string s) {
        vector<string> res;     
        if(s.size()<4 || s.size()>12)
            return res;
        
        
        string temp;
        restoreIpAddresses(s, res, temp, 0, 0);
        return res;
            
    }
};

int main()
{
    string s("010010");
    vector<string> res = Solution::restoreIpAddresses(s); 
    for(int i = 0; i < res.size(); i++)
    {
        printf("%s\n", res[i].c_str()); 
    }
}

