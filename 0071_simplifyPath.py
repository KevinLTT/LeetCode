class Solution:
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        path_stack = ['/']
        tokens = path.split('/')
        print(tokens)
        for token in tokens:
            if len(token) > 0 and token != '.':
                if token == '..': 
                    if len(path_stack) > 1:
                        path_stack.pop()
                else:
                    path_stack.append(token)
        
        if len(path_stack) > 1:
            path = ''
            for index in range(1, len(path_stack)):
                path = path + '/' + path_stack[index]
        else:
            path = '/'
        
        return path
