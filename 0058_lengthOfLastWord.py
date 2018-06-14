class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.strip("\n ").split(" ")
        if s:
            return len(s[-1])
        else:
            return 0
