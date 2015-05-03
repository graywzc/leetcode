class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int size = digits.size();
        vector<int> res(size);      
        int carry = 1;
        for(int i = size-1; i >= 0; i--)
        {
            if(digits[i] == 9 && carry == 1)
            {
                carry = 1; 
                res[i] = 0;
            }
            else
            {
                res[i] = digits[i] + carry;
                carry = 0;
            }
        }

        if(carry == 1)
        {
            res.assign(size+1, 0);
            res[0] = 1;
        }

        return res;

    }
};
