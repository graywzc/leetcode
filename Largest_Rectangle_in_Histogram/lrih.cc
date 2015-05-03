class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int nbar = height.size();        
        if(nbar == 0)
            return 0;
        int i = 0;
        int maxr = 0;
        while(i < nbar)
        {
            if(height[i]>0)
            {
                int local_maxr = height[i]; 
                int maxh = height[i];
                int j = i+1; 
                while(j < nbar && height[j] > 0)
                {
                    if(height[j] > maxh)
                    {
                        j++;
                    }
                    else
                    {
                        int rec = maxh*(j - i);
                        maxh = height[j];
                        if(rec > local_maxr)
                            local_maxr = rec;
                        j++;
                    }
                }

                int rec = maxh*(j - i); 
                if(rec > local_maxr)
                    local_maxr = rec;

                if (maxr < local_maxr)
                    maxr = local_maxr;
            }
            i++; 
        }

        return maxr;
    }
};
