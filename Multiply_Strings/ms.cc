#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:

    static string sum(string num1, string num2)
    {
        string res;
        int size1 = num1.size();         
        int size2 = num2.size();
        int i1 = size1 - 1, i2 = size2 - 1;
        int carry = 0;
        while(i1 >= 0  && i2 >= 0)
        {
            int n1 = num1[i1] - '0';
            int n2 = num2[i2] - '0';
            int sum = n1 + n2 + carry;
            res.push_back('0' + (sum%10));
            carry = sum/10;
            i1--;
            i2--;
        }
        while(i1 >= 0 )
        {
            int n1 = num1[i1] - '0'; 
            int sum = n1 + carry;
            res.push_back('0' + (sum%10));
            carry = sum/10;
            i1--;
        }
        while(i2 >= 0 )
        {
            int n2 = num2[i2] - '0'; 
            int sum = n2 + carry;
            res.push_back('0' + (sum%10));
            carry = sum/10;
            i2--;
        }
        if(carry > 0)
            res.push_back('0'+carry); 
        reverse(res.begin(), res.end());
        return res;
    }

    static string multiply(string num1, string num2) {
        string res;
        if(num1.size() == 1)
        {
            int n1 = num1[0] - '0';
            if(n1 == 0)
            {
                res.push_back('0'); 
                return res;
            }
            int carry = 0;
            int i = num2.size()-1;
            while(i >= 0)                 
            {
                int n2 = num2[i] - '0';
                n2 = n1*n2 + carry;
                res.push_back((n2%10) + '0');
                carry  = n2/10;
                i--; 
            }
            if(carry > 0)
                res.push_back(carry + '0');
            
            reverse(res.begin(), res.end());
            return res;
        }
        else if (num2.size() == 1)
        {
            int n2 = num2[0]-'0';     
            if(n2==0)
            {
                res.push_back('0'); 
                return res;
            }
            int carry = 0;
            int i = num1.size()-1;
            while(i >= 0)
            {
                int n1 = num1[i]-'0'; 
                n1 = n1*n2 + carry;
                res.push_back((n1%10) + '0');
                carry = n1/10;
                i--; 
            }
            if(carry > 0)
                res.push_back(carry+'0');
            reverse(res.begin(), res.end());
            return res;
        }
        else
        {
            int size1 = num1.size(); 
            int size2 = num2.size();
            
            int hs1 = size1/2; 
            int hs2 = size2/2;
            string ac = multiply(num1.substr(0,hs1), num2.substr(0,hs2));
            string ad = multiply(num1.substr(0,hs1), num2.substr(hs2,size2-hs2));
            string bc = multiply(num1.substr(hs1,size1-hs1), num2.substr(0,hs2));
            string bd = multiply(num1.substr(hs1,size1-hs1), num2.substr(hs2,size2-hs2));
            ac+=string(size1-hs1+size2-hs2,'0');
            ad+=string(size1-hs1,'0');
            bc+=string(size2-hs2,'0');
            res = sum(ac,ad);
            res = sum(res,bc);
            res = sum(res, bd);
            
            return res;
        }
    }
};

int main()
{
    string num1("123");
    string num2("456");
    string res = Solution::multiply(num1,num2);
    printf("%s\n", res.c_str());
}
