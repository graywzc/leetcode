#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <algorithm>
#include <set>
using namespace std;


class Solution {
public:

    static void buildpath(vector<vector<string> > &res, 
                          const string& s, 
                          const unordered_map<string,vector<string>> &backmap, 
                          vector<string> &temp)
    {
        if(backmap.find(s) == backmap.end())
        {
            vector<string> path(temp);
            path.push_back(s);
            reverse(path.begin(), path.end());
            res.push_back(path);
            return;
        }
        else
        {
            unordered_map<string,vector<string>>::const_iterator it = backmap.find(s);
            temp.push_back(s);
            for(int i = 0; i < it->second.size(); i++)
            {
                buildpath(res, it->second[i], backmap, temp);     
            }
            temp.pop_back();
            return;
        }
    }

    static vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> >  res;
        int wl = start.size();            


        vector<set<string>> qu(2);

        int current = 0;
        int next = 1;

        unordered_map<string, vector<string>> backmap;

        qu[current].insert(start); 

        while(true)
        {
            bool findit = false;
            qu[next].clear();
            for(string cur: qu[current])
            {
                dict.erase(cur); 
            }
            for(string cur: qu[current])
            {
                for(int i = 0; i < wl; i++)
                {
                    string temp = cur; 
                    for(char j = 'a'; j <= 'z'; j++)
                    {
                        if(j == cur[i]) 
                            continue;
                        temp[i] = j;

                        if(temp.compare(end) == 0)
                        {
                            findit = true; 
                            backmap[end].push_back(cur);
                        }
                        else if(dict.find(temp)!=dict.end())
                        {
                            qu[next].insert(temp); 
                            backmap[temp].push_back(cur);
                        }
                        
                    }
                }
            }

            current = 1-current;
            next = 1-next;
            
            if(qu[current].size() == 0 || findit)
                break;
        }

        
        vector<string> temp;
        if(backmap.find(end)!=backmap.end())
            buildpath(res, end, backmap, temp);

        return res;

    }
};


int main()
{
    string start("qa");
    string end("sq");
    unordered_set<string> dict({"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"});

    vector<vector<string>> res = Solution::findLadders(start, end, dict);
    for(vector<string> vs: res)
    {
        for(string s: vs)
            printf("%s ", s.c_str());
        printf("\n");
            
    }
}

