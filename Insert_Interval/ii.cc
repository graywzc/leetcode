/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;         
        int i = 0;
        while(i < intervals.size() && newInterval.start > intervals[i].end)
        {
            res.push_back(intervals[i]);     
            i++;
        }

        if(i == intervals.size())
        {
            res.push_back(newInterval); 
            return res;
        }

        if(newInterval.start<intervals[i].start)
        {
            if(newInterval.end < intervals[i].start) 
            {
                res.push_back(newInterval);
            }
            else
            {
                int j = i + 1; 
                while(j < intervals.size() && intervals[j].start <= newInterval.end)
                {
                    j++; 
                }
                newInterval.end = max(newInterval.end, intervals[j-1].end);
                res.push_back(newInterval);
                i = j;
            }
        }
        else
        {
            int j = i + 1; 
            while(j < intervals.size() && intervals[j].start <= newInterval.end)
            {
                j++; 
            }
            newInterval.start = intervals[i].start;
            newInterval.end = max(newInterval.end, intervals[j-1].end);
            res.push_back(newInterval);
            i = j;
        }

        while(i < intervals.size()) 
        {
            res.push_back(intervals[i]);
            i++; 
        }

        return res;
        
    }
};

