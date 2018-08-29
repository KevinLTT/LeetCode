class Solution:
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        
        if m == n:
            return head
        
        temp_head = ListNode(0)
        temp_head.next = head        
        count = 1
        pre = temp_head
        p = head
        while p:
            if count == m:
                seg_tail = p
                seg_pre = pre
                pre = p
                p = p.next
            elif m < count < n:
                p_next = p.next    
                p.next = pre
                pre = p
                p = p_next
            elif count == n:
                seg_tail.next = p.next        
                seg_pre.next = p
                p.next = pre
            else:
                pre = p
                p = p.next    
            
            count += 1
        
        return temp_head.next
