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
        
        dummy = ListNode(0)
        pre_valid = dummy
        pre = None
        
        p = head
        while p:
            if p.next is None or p.next.val != p.val:
                pre_valid.next = p
                pre_valid = p
                
                while p.next and p.next.val == p.val:
                    p = p.next
            
            p = p.next
        
        return dummy.next
                    
