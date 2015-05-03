class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> ll;        
        stack<int> prev_vp;
        int i = 0;
        int local_lvp = 0;
        int lvp = 0;
        while(i < s.size())
        {
            if(s[i] == '(')
            {
                ll.push(i);         
                if(local_lvp > 0)
                {
                    prev_vp.push(local_lvp);
                    local_lvp = 0;
                }
            }
            else if(s[i] == ')')
            {
                if(ll.size() == 0) 
                {
                    if(local_lvp>0)
                    {
                        lvp = max(lvp, local_lvp);
                        local_lvp = 0;
                    }
                }
                else
                {
                    int last_left = ll.top();  
                    ll.pop();
                    local_lvp = (i - last_left + 1);
                    if(last_left>0 && s[last_left-1] == ')' && prev_vp.size()>0)
                    {
                        local_lvp += prev_vp.top(); 
                        prev_vp.pop();
                    }
                }
            }
            else
                assert(0);
            i++; 
        }

        lvp = max(lvp,local_lvp);
        while(prev_vp.size() > 0)
        {
            lvp = max(lvp, prev_vp.top()); 
            prev_vp.pop();
        }
        return lvp;
        
    }
};
