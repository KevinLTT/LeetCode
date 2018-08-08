from collections import Counter

class Solution:
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        target = Counter()
        for t_char in t:
            target[t_char] += 1
#         print(target)
        counter = Counter()
        valid_count = 0
        total = len(t)
        min_left, min_right = -1, len(s)
        
        left = 0
        for i, c in enumerate(s):
#             print(f'{i} {c}: counter = {counter}')
            if c in target:
                counter[c] += 1
                if counter[c] <= target[c]:
                    valid_count += 1
                    
                if valid_count == total:
                    right = i
                    for j in range(left, right+1):
                        char = s[j]
                        if char in target:
                            if counter[char] == target[char]:
                                left = j
                                break
                            else:
                                counter[char] -= 1
                    if right - left < min_right - min_left:
                        min_left, min_right = left, right
                    
                    counter[s[left]] -= 1
                    valid_count -= 1
                    left = left + 1
        
        if min_left == -1:
            return ''
        else:
            return s[min_left : min_right+1]
