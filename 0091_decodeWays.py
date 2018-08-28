class Solution:
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        size = len(s)    
        dp = [1] * (size + 1)
        dp[size-1] = 1 if s[size-1] != '0' else 0

        for index in range(size-2, -1, -1):
            if s[index] == '0':
                dp[index] = 0
            elif s[index] == '1' or s[index] == '2' and s[index+1] <= '6':
                dp[index] = dp[index+1] + dp[index+2]
            else:
                dp[index] = dp[index+1]    

            if dp[index] == 0 and dp[index+1] == 0:
                return 0

        return dp[0]    
