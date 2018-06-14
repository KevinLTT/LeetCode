# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, res, new):
        if res and res[-1].end >= new.start:
            if res[-1].end < new.end:
                res[-1].end = new.end
        else:
            res.append(new)  
    
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        
        res = []
        over = False
        for index, inter in enumerate(intervals):
            if not over and newInterval.start < inter.start:
                self.merge(res, newInterval)
                self.merge(res, inter)
                over = True
            else:
                self.merge(res, inter)
        if not over:       
            self.merge(res, newInterval)
                
        return res        
            
