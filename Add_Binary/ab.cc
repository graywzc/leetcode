#include <string>
using namespace std;

class Solution {
public:
    static string addBinary(string a, string b) {
        if(0 == a.size())
            return b;
        if(0 == b.size())
            return a;

        
        int size = max(a.size(), b.size()); 
        string res(size,'0');

        string::reverse_iterator ita = a.rbegin();
        string::reverse_iterator itb = b.rbegin();
        int idx = res.size()-1;
        bool carry = false;
        for(;ita!=a.rend()&&itb!=b.rend();ita++,itb++,idx--)
        {
            res[idx] = (((*ita)==(*itb))==carry)?'1':'0';
            carry = ((*ita)=='1'&&(*itb)=='1')||(((*ita)=='1'||(*itb)=='1')&&carry);
        }
        if(ita == a.rend())
        {
            for(;itb!=b.rend();idx--,itb++) 
            {
                res[idx] = (((*itb)=='0')==carry)?'1':'0';
                carry = (((*itb)=='1')&&carry);
            }
        }
        else
        {
            for(;ita!=a.rend();idx--,ita++)
            {
                res[idx] = (((*ita)=='0')==carry)?'1':'0';
                carry = (((*ita)=='1')&&carry);
            }
        }

        if(carry)
            res.insert(0,1,'1');

        return res;
         
    }
};

int main()
{
    string s1 = "1";
    string s2 = "111";
    string s3 = Solution::addBinary(s1,s2);
}
