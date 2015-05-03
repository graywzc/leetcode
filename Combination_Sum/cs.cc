class Solution {
public:

    void combinationSum(vector<vector<int> > &res, vector<int> &temp, const vector<int> &candidates, int i, int target)
    {
        if(i == candidates.size())     
            return;

        int num = candidates[i];
        int count = 0;
        while(target >= num)
        {
            combinationSum(res, temp, candidates, i+1, target); 
            target -= num;
            temp.push_back(num);
            count++;
            if(0 == target)
            {
                res.push_back(temp);
                break;  
            }
        }

        while(count>0)
        {
            temp.pop_back();
            count--; 
        }
        
        return;
    }
    

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());  

        vector<vector<int> > res;
        vector<int> temp;
        combinationSum(res, temp, candidates, 0, target);

        return res;
        
    }
};
