class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> ascending;
        height.push_back(0);

        int i = 0;
        int maxr = 0;
        while(i < height.size())
        {
            if(ascending.size() == 0 || height[i]>=height[ascending.top()])
            {
                ascending.push(i); 
            }
            else
            {
                while(ascending.size()!=0 && height[ascending.top()] > height[i]) 
                {
                    int h = height[ascending.top()]; 
                    ascending.pop();
                    int left = (ascending.size() == 0)?-1:ascending.top();
                    int right = i;
                    int rec = (right - left - 1)*h;
                    if(rec > maxr)
                        maxr = rec;
                }

                ascending.push(i);
            }
            i++; 
        }

        return maxr;
    }
};
