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
    static bool interval_compare(const Interval& a, const Interval& b)
    {
        if( a.start != b.start )
            return a.start < b.start;
        else
            return a.end < b.end;
    }
    
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort( intervals.begin(), intervals.end(), interval_compare );
        auto itr = intervals.begin();
        while( itr != intervals.end() )
        {
            auto nextItr = itr+1;
            if( nextItr != intervals.end() && nextItr->start <= itr->end )
            {
                nextItr->start = itr->start;
                nextItr->end = itr->end > nextItr->end ? itr->end : nextItr->end;
                itr = intervals.erase(itr);
            }
            else
                itr++;
        }
        
        return intervals;
    }
};
