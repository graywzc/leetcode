#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    static vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        if(n==0) return res;
        int temp = 0;
        for(int i = 1; i <= ((1<<n)-1); i++)
        {
            int diff = 1; 
            int j = i;
            while((j%2)==0)
            {
                diff = diff<<1;  
                j = j>>1;
            }
            temp = temp^diff;
            res.push_back(temp);
        }
        return res;
    }
};

int main()
{
    vector<int> res = Solution::grayCode(2);
}
