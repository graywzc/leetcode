class Solution {
public:
    int longestConsecutive(vector<int> &num) {

        if(num.size() == 0)
            return 0;

        unordered_map<int, int> ht;
        vector<int> visited(num.size());
        for(int i = 0; i < num.size(); i++) 
        {
            if(ht.find(num[i])==ht.end())
            {
                ht.insert(pair<int, int>(num[i], i));     
                visited[i] = 0;
            }
            else
                visited[i] = 1;
        }

        int lc = 0;
        int length;
        for(int i = 0; i < num.size(); i++)
        {

            if(visited[i] == 1)
                continue;

            visited[i] = 1;  
            length = 1;

            int index = num[i] + 1;
            while(ht.find(index) != ht.end())
            {
                visited[ht[index]] = 1;
                length++;
                index++;
            }
            index = num[i] - 1;
            while(ht.find(index)!= ht.end())
            {
                visited[ht[index]]  = 1;
                length++;
                index--;
            }

            if(length>lc)
                lc = length;
        }

        return lc;
    }
};
