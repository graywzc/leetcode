class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();        
        if(size < 2)
            return true;
        
        int i = 0, j = size - 1;
        while(i < j)
        {
            if(!isalnum(s[i])) 
            {
                i++;
                continue;
            }
            else if(!isalnum(s[j]))
            {
                j--; 
                continue;
            }
            else
            {
                if(tolower(s[i]) == tolower(s[j]))
                {
                    i++;
                    j--;
                    continue;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
