#include "u.h"

class Solution {
public:
    int reverseK( ListNode *head, int k, ListNode *& newHead, ListNode *& newTail, ListNode *& newTailNext )
    {
        if( k < 0 )
            return -1;

        int count = 0;
        auto p = head;
        while( p )
        {
            count++;
            p = p->next;
            if( count >= k )
                break;
        }
        if( count < k )
            return -1;

        newTail = head;
        ListNode *pre, *next;
        p = head;
        for( int i = 0; i < k; i++ )
        {
            next = p->next;
            p->next = pre;
            pre = p;
            p = next;
        }
        newHead = pre;
        newTailNext = p;
        return 0;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *pre, *h, *newHead, *newTail, *newTailNext;
        ListNode *result;
        if( reverseK( head, k, newHead, newTail, newTailNext ) != 0 )
            return head;
        else
        {
            result = newHead;
            newTail->next = newTailNext;
            h = newTailNext;
            pre = newTail;
        }

        while( 1 )
        {
            if( reverseK( h, k, newHead, newTail, newTailNext ) != 0 )
                break;

            h = newTailNext;
            pre->next = newHead;
            pre = newTail;
            newTail->next = newTailNext;
        }

        return result;
    }
};
