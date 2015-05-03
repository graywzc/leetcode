/**
 * Definition for an interval.
 */ 
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
class Solution {
public:
    
    static bool comp(Interval a, Interval b)
    {
        return a.start < b.start ; 
    }
    
    static vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        if(intervals.size() == 0)
            return res;
        sort(intervals.begin(), intervals.end(), comp);

        res.push_back(intervals[0]);

        for(Interval& a: intervals) 
        {
            if(a.start == res.back().start)
            {
                if(a.end > res.back().end)
                    res.back().end = a.end;
            }
            else
            {
                if(a.start <= res.back().end ) 
                {
                    if (a.end > res.back().end)
                        res.back().end = a.end; 
                }
                else
                {
                    res.push_back(a); 
                }
            }
        }

        return res;
    }
};

int main()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(0,4));
    intervals.push_back(Interval(1,4));

    vector<Interval> res = Solution::merge(intervals);

    for(Interval& a: res)
    {
        printf("[%d %d] ", a.start, a.end); 
    }
    printf("\n");
}
