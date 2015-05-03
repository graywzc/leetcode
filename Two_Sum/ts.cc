class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        map<int,int> tbl;
        map<int,int>::iterator it;
        
        int i=0;
        while(i<numbers.size())
        {
            it = tbl.find(numbers[i]);
            if(it!=tbl.end())
            {
                res.push_back(it->second+1);
                res.push_back(i+1);
                return res;
            }
            else
            {
                tbl.insert(pair<int,int>(target-numbers[i],i));
            }
            i++;
        }
        
    }
};
