class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        seq = "1"
        for i in range (1, n):
            newSeq = ""
            pre = ""
            count = 0
            for j in range( len(seq) ):
                if( pre == seq[j] ):
                    count += 1
                else:
                    if(count != 0):
                        newSeq = newSeq + str(count) + str(pre)
                    pre = seq[j]
                    count = 1
            newSeq = newSeq + str(count) + str(pre)
            seq = newSeq
        return seq