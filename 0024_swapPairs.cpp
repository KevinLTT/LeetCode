#include "u.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if( !head || !head->next )
            return head;    

        ListNode *h = new ListNode(0);
        ListNode *p = head;
        ListNode *pre = h;
        while( p && p->next )
        {
            pre->next = p->next;
            pre = p;

            ListNode* nextNext = p->next->next;
            p->next->next = p;
            p->next = nextNext;
            p = p->next;
        }

        return h->next;
    }
};

void printList( ListNode *l ) 
{
    while( l )
    {
        cout << l->val << "<-";
        l = l->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    printList( head );
    Solution s;
    head = s.swapPairs( head );
    printList( head );

    return 0;
}
