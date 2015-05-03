class Solution {
public:
    int candy(vector<int> &ratings) {
        if(ratings.size() == 0)        
            return 0;
        if(ratings.size() == 1)
            return 1;

        int size = ratings.size();
        int *nc = new int[size];
        int i = 1;
        nc[0] = 1;
        bool isRising = false;
        bool isFalling = false;
        int falling_start = 0;

        while(i < size)
        {
            int curr = ratings[i];
            int past = ratings[i-1];
            if(curr>past)
            {
                if(isFalling)      
                {
                    if(nc[i-1]<1) 
                    {
                        for(int j = falling_start; j < i; j++)  
                            nc[j] += (1-nc[i-1]); 
                    }
                    else if(nc[i-1]>1)
                    {
                        for(int j = falling_start+1; j<i; j++) 
                            nc[j] -= (nc[i-1]-1); 
                    }
                    isFalling = false; 
                }
                nc[i] = nc[i-1] + 1;
                isRising = true;
            }
            else if(curr<past)
            {
                if(!isFalling) 
                {
                    isFalling = true; 
                    falling_start = i-1;
                    isRising = false;
                }
                nc[i] = nc[i-1] - 1;
            }
            else
            {
                if(isRising)
                {
                    nc[i] = 1;
                    isRising = false;
                }
                else if(isFalling)
                {
                    if(nc[i-1]<1) 
                    {
                        for(int j = falling_start; j < i; j++)  
                            nc[j] += (1-nc[i-1]); 
                    }
                    else if(nc[i-1]>1)
                    {
                        for(int j = falling_start+1; j<i; j++) 
                            nc[j] -= (nc[i-1]-1); 
                    }
                    nc[i] = 1;
                    isFalling = false;
                }
                else
                    nc[i] = 1;
            }
            i++; 
        }

        if(isFalling)
        {
            if(nc[i-1]<1) 
            {
                for(int j = falling_start; j < i; j++)  
                    nc[j] += (1-nc[i-1]); 
            }
            else if(nc[i-1]>1)
            {
                for(int j = falling_start+1; j<i; j++) 
                    nc[j] -= (nc[i-1]-1); 
            }     
        }

        int res = 0;
        i = 0;
        while(i<size)
        {
            res+=nc[i];
            i++; 
        }
        delete [] nc;
        return res;
    }
};
