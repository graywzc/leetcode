class Solution {
public:
    string num2str(int num)
    {
        char digits[10];
        string res;  
        int i = 0;
        while(num > 0)
        {
            digits[i] = '0' + (num%10);
            i++;
            num = num/10;
        }
        i--;
        while(i>=0)
        {
            res.push_back(digits[i]);
            i--; 
        }
        return res;
    }
    string onestep(const string & s)
    {
        string res;
        int i = 0;
        while(i < s.size())
        {
            int num = s[i] - '0'; 
            int j = i+1;
            int count = 1;
            while(j < s.size() && s[j] == s[i])
            {
                count++; 
                j++;
            }

            res+=num2str(count);
            res.push_back(s[i]);
            i = j;
            
        }

        return res;
    }
    
    string countAndSay(int n) {
        int i = 1;            
        string res;
        res.push_back('1');
        while(i < n)
        {
           res = onestep(res); 
           i++;
        }
        return res;
    }
};
