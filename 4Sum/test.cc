#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <climits>
using namespace std;

class Solution {
public:
    static vector<vector<int> > fourSum(vector<int> &num, int target) {
        std::sort(num.begin(), num.end());
        int length = num.size();
        vector<vector<int> > res;
        for (int i = 0; i < length - 3; i++)
        {
            for (int j = i+1; j < length-2; j++)
            {
                int k = j+1;
                int l = length-1;
                while(k<l)
                {
                    int temp = num[i]+num[j]+num[k]+num[l]-target;
                    if (temp == 0)
                    {
                        vector<int> temp;
                        temp.push_back(num[i]);
                        temp.push_back(num[j]);
                        temp.push_back(num[k]);
                        temp.push_back(num[l]);
                        res.push_back(temp);
                        k++;l--;
                        while(num[k] == num[k-1] && num[l] == num[l+1] && k<l) 
                        {k++;l--;}
                    }
                    else if (temp<0)
                    {
                        k++;
                    }
                    else
                        l--;
                }
                
                while(num[j] == num[j+1]) j++;
            }
            while(num[i] == num[i+1]) i++;
        }
        
        return res;
    }
};


int main()
{
    vector<int> num;
    num.assign(4,0);
    vector<vector<int> > res = Solution::fourSum(num,0);
    int l = res.size();
    printf("%d\n",l);
}
