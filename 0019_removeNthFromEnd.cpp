#include "u.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if( n <= 0 )
            return head;

        ListNode *node = head, *nth = nullptr, *pre = nullptr;
        while( node )
        {
            n--;

            if( n == 0 )
                nth = head;
            else if( n < 0 )
            {
                pre = nth;
                nth = nth->next;
            }

            node = node->next;
        }

        if( nth )
        {
            if( pre )
                pre->next = nth->next;
            else
                return nth->next;
        }
        return head;
    }
};
