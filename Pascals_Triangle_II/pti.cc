class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        if(rowIndex == 0)
            return res;
        int flag = 0;
        for(int i = 1; i <= rowIndex; i++)
        {
            if(flag == 0) 
            {
                vector<int> temp(res.size());
                temp[0] = 1;
                for(int j = 1; j < res.size(); j++) 
                {
                    temp[j] = res[j-1] + res[j];
                }
                res = temp;
            }
            else
            {
                vector<int> temp(res.size()); 
                temp[0] = 1;
                for(int j = 1; j < res.size(); j++)
                {
                    temp[j] = res[j-1] + res[j];
                }
                temp.push_back(res.back() * 2);
                res = temp;
            }

            flag = 1-flag;
        }

        if(flag == 0)
        {
            for(int i = res.size()-2; i>= 0; i--)  
                res.push_back(res[i]); 
        }
        else
        {
            for(int i = res.size()-1; i>=0; i--) 
                res.push_back(res[i]);
        }

        return res;
    }
};
