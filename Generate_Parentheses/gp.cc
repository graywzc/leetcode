#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    
    static void addP(vector<string>& res, string &temp, int nLeft, int nRight, int n)
    {
        if(nLeft == n) 
        {
            int i = n - nRight; 
            string temp1 = temp;
            while(i>0)
            {
                temp1.push_back(')');
                i--;
            }
            res.push_back(temp1);
            return;
        }
        temp.push_back('(');
        addP(res, temp, nLeft+1, nRight, n);
        temp.pop_back();
        if(nRight<nLeft)
        {
            temp.push_back(')'); 
            addP(res, temp, nLeft, nRight+1, n);
            temp.pop_back();
        }
        return;
        
    }

    static vector<string> generateParenthesis(int n) {
        vector<string> res;        
        int nLeft = 0;
        int nRight = 0;
        string temp;        
        addP(res, temp, nLeft, nRight, n);
        return res; 
    }
};

int main()
{
    vector<string> res = Solution::generateParenthesis(3);
    for(int i = 0; i < res.size(); i++)
    {
        printf("%s\n", res[i].c_str()); 
    }
}
