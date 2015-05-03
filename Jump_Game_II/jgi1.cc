// greedy method, best solution
class Solution {
public:
    int jump(int A[], int n) {
        int i = 0; 
        int range = 0;
        int num = 0;
        while(1)
        {
            if(range>=n-1)
                return num;
            num ++;
            int local = i;
            while(i <= range)
            {
                local = max(local, i+A[i]);
                i++;
            }
            if(local > range)
                range = local;
            else
                return -1;
        }
    }
};
