class Solution:
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        def binary2decimal(bi_list):
            num = 0
            size = len(bi_list)
            for idx, digit in enumerate(bi_list):
                if digit == 1:
                    num += 2 ** (size - idx - 1)
            return num    
        
        def gray(state, bit_left, reses):
            if bit_left == 1:
                reses.append(state.copy())
                state[-1] = 1 if state[-1] == 0 else 0
                reses.append(state.copy())
                return
            
            gray(state, bit_left-1, reses)
            state[-bit_left] = 1 if state[-bit_left] == 0 else 0
            gray(state, bit_left-1, reses)
            

        if n <= 0:
            return [0]    
        
        initial_state = [0] * n
        reses = list()
        gray(initial_state, n, reses)
        

        return [binary2decimal(x) for x in reses]
