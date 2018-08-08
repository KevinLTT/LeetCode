class Solution:
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        
        def search(board, valid_board, target_word, pos, count):
            if count >= len(target_word):
                return True
            
            height = len(board)
            width = len(board[-1])
            if count == 0:
                for y in range(height):
                    for x in range(width):
                        if board[y][x] == target_word[0]:
                            valid_board[y][x] = False
                            hit = search(board, valid_board, target_word, (x, y), count+1) 
                            if hit is True:
                                return True
                            valid_board[y][x] = True
                return False            
            else:
                x, y = pos[0], pos[1]
                x_acc = [1, 0, -1, 0]
                y_acc = [0, 1, 0, -1]                
                for i in range(4):
                    x_next = x + x_acc[i]
                    y_next = y + y_acc[i]
                    if x_next >= 0 and x_next < width and \
                       y_next >= 0 and y_next < height and \
                       valid_board[y_next][x_next] is True and \
                       board[y_next][x_next] == target_word[count]:
                        valid_board[y_next][x_next] = False
                        hit = search(board, valid_board, target_word, (x_next, y_next), count+1) 
                        if hit is True:
                            return True
                        valid_board[y_next][x_next] = True
                return False        
        
        if not board or not board[0]:
            return False
        if not word:
            return True    
        
        valid_row = [True] * len(board[0])
        valid_board = list()
        for i in range(len(board)):
            valid_board.append(valid_row.copy())
        return search(board, valid_board, word, (0, 0), 0)
