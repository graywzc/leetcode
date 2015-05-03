// dynamic proramming solution
class Solution {
public:
#define md(x,y) md[(x)*(size2+1) + (y)]

    int minDistance(string word1, string word2) {
        const char *pw1 = word1.c_str();    
        const char *pw2 = word2.c_str();
        int size1 = word1.size();
        int size2 = word2.size();

        int *md = new int[(1+size1)*(1+size2)];

        for(int i = 0; i <= size2; i++)
            md(0,i) = i;
        for(int i = 0; i <= size1; i++)
            md(i,0) = i;

        for(int i = 1; i <= size1; i++)
            for(int j = 1; j <= size2; j++)
            {
                md(i,j) = 1 + md(i-1,j); 
                int temp = 1 + md(i,j-1);
                if(temp < md(i,j))
                    md(i,j) = temp;
                temp = md(i-1,j-1) + ((word1[i-1]==word2[j-1])?0:1);
                if(temp < md(i,j))
                    md(i,j) = temp;
            }
        
        int res = md(size1, size2);
        delete [] md;
        return res;
    }
};
