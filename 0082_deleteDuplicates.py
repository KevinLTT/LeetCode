# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        temp_head = ListNode(-1)
        pre_valid = temp_head
        pre = None
        
        p = head
        while p is not None:
            print('p: {}, pre: {}, next: {}, pre_valid: {}'.format(p.val, 
                                                                   pre if pre is None else pre.val, 
                                                                   p.next if p.next is None else p.next.val, 
                                                                   pre_valid.val))
            if ((pre is None or pre.val != p.val) and
                 (p.next is None or p.next.val != p.val)):
                pre_valid.next = ListNode(p.val)
                pre_valid = pre_valid.next
            
            pre = p
            p = p.next
                               
        
        return temp_head.next
