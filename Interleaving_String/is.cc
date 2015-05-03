class Solution {
public:
#define is(i,j) is[(size2+1)*(i)+(j)]
    bool isInterleave(string s1, string s2, string s3) {
        
        int size1 = s1.size();
        int size2 = s2.size();
        int size3 = s3.size();
        if((size1+size2)!=size3)
            return false;
        if(size1 == 0)
            return (s2.compare(s3) == 0);
        if(size2 == 0)
            return (s1.compare(s3)==0);
        bool *is = new bool[(size1+1)*(size2+1)];        
        
        is(0,0) = true;
        for(int j = 1; j <= size2; j++)
            is(0,j) = is(0,j-1) && (s2[size2-j]==s3[size3-j]); 
        for(int i = 1; i <= size1; i++)
            is(i,0) = is(i-1,0) && (s1[size1-i]==s3[size3-i]);

        
        for(int i = 1; i <= size1; i++)
            for(int j = 1; j <= size2; j++)
            {
                is(i,j) = ((s1[size1-i]==s3[size3-i-j])&&is(i-1,j))||
                          ((s2[size2-j]==s3[size3-i-j])&&is(i,j-1));
            }
        bool res = is(size1, size2);
        delete [] is;
        return res;
    }
};

