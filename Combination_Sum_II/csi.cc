#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    static void combinationSum2(const vector<int> &num, int target, vector<vector<int> >& res, vector<int> &temp, int i)
    {
        if(i == num.size() || target < num[i]) 
        {
            return; 
        }
        else
        {
            int n = num[i];  
            int j = i+1;
            int count = 1;
            while(j < num.size() && num[j] == n)
            {
                count++;
                j++;
            }

            combinationSum2(num, target, res, temp, j);

            int k = 0;
            while(k < count)
            {
                target -= n;
                temp.push_back(n);
                k++;
                if(target == 0)
                    res.push_back(temp);      
                else if (target>0)
                    combinationSum2(num, target, res, temp, j);
                else
                    break;
            }
                 
            while(k>0)
            {
                temp.pop_back();
                k--;
            }

            return;
            
        }
    }
    static vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end()); 

        vector<vector<int> > res;
        vector<int> temp;

        combinationSum2(num, target, res, temp, 0);
        
        return res;
    }
};

int main()
{
    vector<int> num(1,1);
    vector<vector<int> > res = Solution::combinationSum2(num, 1);
}
