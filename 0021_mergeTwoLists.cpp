#include "u.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head;
        head = new ListNode(0);
        ListNode *p = head;
        while( l1 && l2 )
        {
            if( l1->val < l2->val )
            {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }

        auto rest = l1 ? l1 : l2;
        while( rest )
        {
            p->next = rest;
            rest = rest->next;
            p = p->next;
        }
        
        return head->next;
    }
};
