class Solution:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        
        if len(a) > len(b):
            b = b.rjust(len(a), '0')
        elif len(b) > len(a):
            a = a.rjust(len(b), '0')     
            
    
        carry = "0"
        res = ""
        for i in range(-1, -len(a)-1, -1):
            if a[i] == b[i]:
                res = carry + res
                carry = a[i]
            else:
                if carry == "1":
                    res = "0" + res
                else:
                    res = "1" + res
        if carry == "1":
            res = "1" + res

        return str(res)
