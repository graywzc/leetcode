class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0; // each '1' stands for 1 appear once on this bit
        int twos = 0; // each '1' stands for 1 appear one on this bit
        int threes = 0; // each '1' stands for 1 appear three times on this bit

        for (int i = 0; i < n; i++) 
        {
            twos |= (ones&A[i]);
            ones ^= A[i];
            threes = ~(ones&twos);
            ones &= threes;
            twos &= threes;
        }

        return ones;
    }
};
