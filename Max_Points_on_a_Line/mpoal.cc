/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.size() == 0) 
            return 0;
        if(points.size() == 1) 
            return 1;

        int gmax = 0; 

        int i = 0;
        while(i < points.size())
        {
            int nSelf = 1;
            int nVer = 0;
            int lmax = 0;
            map<double,int> derivs;
            map<double,int>::iterator it;
            int j = 0;
            while(j < points.size() && i!=j)
            {
                if(points[i].x == points[j].x && points[i].y == points[j].y)
                {
                    nSelf ++; 
                }
                else if(points[i].x == points[j].x)
                {
                    nVer ++; 
                    if(nVer > lmax)
                        lmax = nVer;
                }
                else
                {
                    double deriv = ((double)(points[i].y - points[j].y))/((double)(points[i].x - points[j].x));
                    it = derivs.find(deriv);
                    if(it == derivs.end())
                    {
                        derivs.insert(pair<double,int>(deriv,1)); 
                        if(lmax<1)
                            lmax = 1;
                    }
                    else
                    {
                        it->second ++;  
                        if(lmax<it->second)
                            lmax = it->second;
                    }
                }

                j++;
            }

            if(gmax<(lmax+nSelf))
                gmax = lmax+nSelf;
            i++; 
        }

        return gmax;
        
    }
};
