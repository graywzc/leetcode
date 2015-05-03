class Solution {
public:
    void reverseWords(string &s) {
        if(s.size() == 0)
            return;

        int i = 0;
        stack<string> st;        
        while(i < s.size())
        {
            if(s[i]==' ')
                i++;
            else
            {
                int j = i+1; 
                while(j < s.size() && s[j]!=' ')
                    j++;

                st.push(s.substr(i,j-i));
                i = j;
            }
        }

        s.clear();
        if(st.size() > 0)
        {
            while(st.size()>0)
            {
                s+=st.top(); 
                s+=" ";
                st.pop();
            }
            s.pop_back();
        }
        return;
    }
};
