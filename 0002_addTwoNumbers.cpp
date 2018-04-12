#pragma once
#include <cmath>
#include <memory>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		int sum = 0, digitSum, exp = 0;
		ListNode *head, *p;
		head = new struct ListNode(-1);
		p = head;
		while (1)
		{
			if (l1 != nullptr && l2 != nullptr)
			{
				digitSum = l1->val + l2->val + carry;

				l1 = l1->next;
				l2 = l2->next;
			}
			else if (l1 != nullptr)
			{
				if (!carry)
					p->next = l1;
				digitSum = l1->val + carry;

				l1 = l1->next;
			}
			else if (l2 != nullptr)
			{
				if (!carry)
					p->next = l2;
				digitSum = l2->val + carry;

				l2 = l2->next;
			}
			else
			{
				if (carry)
					p->next = new struct ListNode(1);
				break;
			}

			carry = digitSum / 10;
			digitSum %= 10;
			p->next = new struct ListNode(digitSum);
			p = p->next;
		}
		
		return head->next;
	}
};