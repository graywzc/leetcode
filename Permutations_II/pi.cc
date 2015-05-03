#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    static void permuteUnique(vector<int>& num, vector<vector<int> > &res, int i)
    {
        if(i == num.size()) 
        {
            res.push_back(num); 
            return;
        }
        else
        {
            permuteUnique(num, res, i+1);
            int j = i+1;
            int prev = num[i];
            while(j<num.size())
            {
                while(j<num.size() && num[j] == prev)
                    j++;
                if(j == num.size())
                    break;
                int temp = num[j];
                num[j] = num[i];
                num[i] = temp;
                permuteUnique(num, res, i+1);
                j++; 
                prev = num[i];
            }

            // important, before return, need to make sure it's in non-descending order from i to end 
            prev = num[i];
            j = i;
            while(j<(num.size()-1))
            {
                num[j] = num[j+1]; 
                j++;
            }
            num[j] = prev;
            
            return;
        }
    }

    static vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;    
        if(num.size() == 0)
            return res;
         
        sort(num.begin(), num.end());
        permuteUnique(num, res, 0);

        return res;
    }
};
int main()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    vector<vector<int> > res = Solution::permuteUnique(num);
    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++) 
            printf("%d ",res[i][j]);
        printf("\n");
    }

}
