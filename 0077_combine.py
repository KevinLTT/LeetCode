class Solution:
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        
        def comb(n, k, results_list, current_list ):
            if len(current_list) >= k:
                results_list.append(current_list.copy())
                return

            begin_num = 0 if not current_list else current_list[-1]
            for next_num in range(begin_num+1, n+2-(k-len(current_list))):
                current_list.append(next_num)
                comb(n, k, results_list, current_list)
                current_list.pop()
                
        results_list = list()
        current_list = list()
        comb(n, k, results_list, current_list)
        return results_list
                
