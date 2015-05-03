#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <climits>
using namespace std;

class Solution {
public:
    static int threeSumClosest(vector<int> &num, int target) {
        std::sort(num.begin(), num.end());
        int l = num.size();
        int min = INT_MAX;
        int res;
        for(int i=0; i < l-2; i++)
        {
            int j = i+1;
            int k = l-1;
            while(j<k)
            {
                int temp = num[i] + num[j] + num[k] - target;
                if(abs(temp) < min)
                {
                    min = abs(temp);
                    res = num[i] + num[j] + num[k];
                }
                if (temp == 0)
                    return target;
                else if (temp>0)
                    k--;
                else
                    j++;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> num;
    num.assign(4,1);
    int res = Solution::threeSumClosest(num,100);
    printf("%d\n",res);
}
