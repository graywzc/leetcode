/*
 Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 */

// my accepted solution
class Solution {
public:
    bool isNumber(const char *s) {
        if (s==NULL)
            return false;
        
        int state = 0;
        bool first_char = false;
        bool e_appear = false;
        bool dot_appear = false;
        bool num = false;
        while(*s != '\0')
        {
            if(*s==' ')
                if( state == 0)
                    s++;
                else if (state == 1)
                {
                    state = 2;
                    s++;
                }
                else
                    s++;
            else
            {
                if(state == 0)
                {
                    state = 1;
                    first_char = true;
                }
                else if (state == 1)
                {
                    first_char = false;
                }
                else
                    return false;
                
                if(*s == '.')
                {
                    if( dot_appear || e_appear ||  *(s+1) == '-' || *(s+1) == '+')
                        return false;
                    else if(first_char)
                    {
                        if(*(s+1)<'0' || *(s+1)>'9')
                            return false;
                        else
                        {
                            s++;
                            dot_appear = true;
                        }
                    }
                    else
                    {
                        s++;
                        dot_appear = true;
                    }
                }
                else if(*s == '-' || *s == '+')
                {
                    if((!first_char && *(s-1) != 'e') )
                        return false;
                    else
                        s++;
                }
                else if(*s == 'e')
                {
                    if(first_char || e_appear || *(s-1) == '-' || *(s-1) == '+' )
                        return false;
                    else
                    {
                        s++;
                        e_appear =  true;
                        num = false;
                    }
                }
                else if(*s >= '0' && *s <= '9' )
                {
                    num = true;
                    s++;
                }
                else
                    return false;
            }
        }
        if ((state == 2 || state == 1) && num)
            return true;
        else 
            return false;
    }
};
        
