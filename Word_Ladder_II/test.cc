#include <vector>
#include <unordered_map>
#include <stdio.h>
#include <string>
using namespace std;


void p(const unordered_map<string,vector<string>> &m, const string &s)
{
    unordered_map<string, vector<string>>::const_iterator it = m.find(s);
    if(it!=m.end())
    {
        printf("ok\n");
    }
/*
    for(string i : m[s])
        printf("%s ", i.c_str());
    printf("\n");
*/
}

int main()
{
    vector<int> a(5,1);
    for(int i: a)
    {
        printf("%d ", i); 
    }
    printf("\n");

    unordered_map<string, vector<string> > m;
    vector<string> vs(5, "abc");

    m["abc"] = vs;

    string s("abc");
    for(string i: m[s])
    {
        printf("%s ", i.c_str()); 
    }
    printf("\n");
}
