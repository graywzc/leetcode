class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (NULL==s)
            return 0;
        int num = 0;
        int lolw = 0;
        while(*s!='\0')
        {
            if(*s!=' ') 
                num++;
            else
            {
                if(num>0)
                {
                    lolw = num; 
                    num = 0;
                }
            }
            s++;
        }

        if(num>0)
            return num;
        else
            return lolw;
    }
};
