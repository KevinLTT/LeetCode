#include "u.h"

class Solution {
public:
    ListNode* megreLists( ListNode *l1, ListNode* l2 )
    {
        ListNode *head = new ListNode( 0 );
        auto p = head;
        while( l1 && l2 )
        {
            if( l1->val < l2->val )
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }

        auto res = l1 ? l1 : l2;
        while( res )
        {
            p->next = res;
            res = res->next;
            p = p->next;
        }
        
        return head->next;
    }


    ListNode* mergeKLists(vector<ListNode*>& lists)  {
        if( lists.empty() )
            return nullptr;

        while( lists.size() > 1 )
        {
            vector<ListNode*> res;
            int i = 0;
            for( i = 0; i < lists.size()-1; i+= 2 )
            {
                auto merged = megreLists( lists[i], lists[i+1] );
                res.push_back( merged );
            }
            if( i < lists.size() )
                res.push_back( lists[i] );
            lists.clear();
            lists.shrink_to_fit();
            lists = res;
        }

        return lists[0];
    }
};
