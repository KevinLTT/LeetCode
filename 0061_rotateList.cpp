#include "u.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int listSize = 0;
        ListNode* p = head;
        while(p != nullptr)
        {
            listSize++;
            p = p->next;
        }
        k = k % listSize;
        if( k == 0 )
            return head;

        int remain = listSize-1;
        auto newTail = head;
        while(remain > k)
        {
            newTail = newTail->next;
            remain--;
        }
        auto newHead = newTail->next;
        newTail->next = nullptr;

        p = newHead;
        while(p->next != nullptr)
            p = p->next;
        p->next = head;

        return newHead;
    }
};
