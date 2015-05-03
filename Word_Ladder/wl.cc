class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {

        if (start.compare(end) == 0)
            return 0;
        
        int wl = start.size();
        
        map<string,int> visited;
        visited.insert(pair<string,int>(start,1));

        queue<string> bfsq;
        bfsq.push(start);

        while(bfsq.size()>0)
        {
            string s1 = bfsq.front(); 
            // check if s1 is neighbouring to end
            int count = 0;
            for(int i = 0; i < wl; i++)
            {
                if(s1[i] != end[i])  
                    count++;
            }
            int lvl = visited[s1];
            if(count == 1)
                return lvl + 1;

            // find neighboring node in dict
            for(int i = 0; i < wl; i++)
            {
                string s2 = s1;
                for(char j = 'a'; j <= 'z'; j++)
                {
                    s2[i] = j; 
                    if(dict.find(s2) != dict.end() && visited.find(s2) == visited.end())
                    {
                        bfsq.push(s2); 
                        visited.insert(pair<string, int>(s2, lvl+1));
                    }
                }
            }

            bfsq.pop();
        }

        return 0;
        
    }
};
