#include <stdio.h>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
#define dp(i,j) dp[n*(i) + (j) - (i)*((i)+1)/2]
    static bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        if(n == 0)
            return true;
            
        bool *dp = new bool[n*(n+1)/2];    
        for(int i = n-1, nword = 0; i >= 0 ; i --, nword++) 
        {
            for(int j = 0; j <= i; j++) 
            {
                dp(j,j+nword) = (dict.find(s.substr(j,nword+1))!=dict.end());
                int k = j;
                while(k<(j+nword))
                {
                    dp(j,j+nword) = dp(j,j+nword) || (dp(j,k) && dp(k+1, j+nword));    
                    k++; 
                }
            }
        }

        bool res = dp(0,n-1);
        delete [] dp;
        return res;
    }
};

int main()
{
    string s("a");
    unordered_set<string> dict;
    dict.insert(s);

    bool res = Solution::wordBreak(s, dict);
    if(res)
        printf("yes\n");
    else
        printf("no\n");
}
