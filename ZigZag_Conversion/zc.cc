class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1)
            return s;
        int l = s.length();
        string res="";
        for(int i = 0; i < nRows; i++)
        {
            int index = i;
            while(index<l)
            {
                res+=s[index];
                if(i==0 || i==(nRows-1))
                {
                    index += 2*(nRows-1);
                }
                else
                {
                    index += 2*(nRows-1-i);
                    if (index<l)
                        res+=s[index];
                    index += 2*i;
                }
            }
        }
        return res;
    }
};
