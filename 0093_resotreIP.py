class Solution:
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        def valid(s):
            if s and 1 <= len(s) <= 3:
                if len(s) == 1 or not s.startswith('0'):
                    s = s.rjust(3, '0')
                    if '000' <= s <= '255':
                        return True        
            return False    
        
        def ip(s, current, index, reses):
            left_position = 4 - len(current)
            left_char = len(s) - index
            
            if left_position == 1 and valid(s[index:]):
                current.append(s[index:])
                reses.append(current.copy())
                current.pop()
                return
            
            if not left_position <= left_char <= left_position * 3:
                return
            
            for i in range(1, 4):
                if index+i <= len(s) and valid(s[index : index+i]):
                    current.append(s[index : index+i])
                    ip(s, current, index+i, reses)
                    current.pop()
        
        reses = []
        index = 0
        current = []
        ip(s, current, index, reses)
        
        ips = []
        for res in reses:
            #ips.append(f'{res[0]}.{res[1]}.{res[2]}.{res[3]}')
            ips.append('{}.{}.{}.{}'.format(res[0], res[1], res[2], res[3]))
        
        return ips        
