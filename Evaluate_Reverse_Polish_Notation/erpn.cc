class Solution {
public:

    int str2int(const string& s)
    {
        int res = 0;
        int i = 0;  
        bool isNeg = false;
        if(s[i] == '-')
        {
            isNeg = true;
            i++;
        }
        while(i < s.size())
        {
            res = res*10 + s[i] - '0'; 
            i++;
        }
        if(isNeg)
            res = 0-res;
        return res;
    }
    int evalRPN(vector<string> &tokens) {
        stack<int> st;        
        int res = 0;
        if(tokens.size() == 0)
            return res;
        int i = 0;
        while(i < tokens.size())
        {
            if(tokens[i].size()==1 && tokens[i][0] == '+')
            {
                assert(st.size()>=2);     
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int sum = op1+op2;
                st.push(sum);
            }
            else if(tokens[i].size()==1 && tokens[i][0] == '-')
            {
                assert(st.size()>=2);     
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int sum = op2-op1;
                st.push(sum); 
            }
            else if(tokens[i].size()==1 && tokens[i][0] == '*')
            {
                assert(st.size()>=2);     
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int sum = op2*op1;
                st.push(sum); 
            }
            else if(tokens[i].size()==1 && tokens[i][0] == '/')
            {
                assert(st.size()>=2);     
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int sum = op2/op1;
                st.push(sum); 
            }
            else{
                st.push(str2int(tokens[i]));
            }
            i++; 
        }

        assert(st.size() == 1);
        res = st.top();
        return res;
    }
};
