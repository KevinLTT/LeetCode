# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        
        small_head = ListNode(0)
        big_head = ListNode(0)
        sp, bp = small_head, big_head
        
        p = head
        while p:
            if p.val < x:
                sp.next = p
                sp = sp.next
            else:
                bp.next = p
                bp = bp.next    
            p = p.next    
        
        sp.next = big_head.next
        bp.next = None
        
        return small_head.next
                
