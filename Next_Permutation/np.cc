class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size() <= 1)       
            return;

        int i = num.size() - 2;
        while( i>=0 && num[i]>=num[i+1])
        {
            i--;
        }

        if(i == -1)
        {
            sort(num.begin(), num.end()); 
            return;
        }
        else
        {
            int j = i+1; 
            while(j <= num.size()-1 && num[j]>num[i])
            {
                j++;
            }
            int temp = num[j-1];
            num[j-1] = num[i];
            num[i] = temp;

            int k = i+1, l = num.size()-1;
            while(k<l)
            {
                temp = num[k]; 
                num[k] = num[l];
                num[l] = temp;
                k++;
                l--;
            }
            return;
        }
        
    }
};
