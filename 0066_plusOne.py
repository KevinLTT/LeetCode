class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        
        carry = 1
        for i in range(-1, -len(digits)-1, -1):
            digits[i], carry = (digits[i] + carry) % 10, (digits[i] + carry) // 10
            if carry is 0:
                break;
        if carry == 1:
            digits.insert(0, 1)        
            
        return digits
