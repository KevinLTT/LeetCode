#include "u.h"
		   
typedef struct linkedNode
{
	int val;
	struct linkedNode* next;
	struct linkedNode* pre;
	
	linkedNode(int v) : val(v), next(nullptr), pre(nullptr) {}
}Node;
typedef Node* node;

class number
{
public:
	int length;
	int positive;
	node num;

	bool headInsert(int d)
	{
		if (d > 10 || d < 0)
			return false;

		auto newNode = new node(d);
		newNode->next = num;
		newNode->pre = nullptr;
		if (num)
			num->pre = newNode;
		num = newNode;

		length++;
	}

	void cleanInvalidDigit()
	{
		node pre = nullptr;
		node p = num;
		while (p && p->val == 0)
		{
			if( p->next )
				p->next->pre = pre;
			if (pre)
				pre->next = p;
			auto temp = p;
			p = p->next;
			delete temp;
			length--;
		}
	}

	number() : length(0), positive(true), num(nullptr) {}

	number(int n)
	{
		positive = n < 0 ? false : true;
		n = abs(n);
		while (n != 0)
		{
			headInsert(n % 10);
			n /= 10;
		}
	}

	bool absLess(const number& number2)
	{
		if (this->length != number2.length)
			return this->length < number2.length ? true : false;

		auto p1 = num;
		auto p2 = number2.num;
		while (p1 && p2)
		{
			if (p1->val != p2->val)
				return p1->val < p2->val ? true : false;

			p1 = p1->next;
			p2 = p2->next;
		}
		return false;
	}

	bool operator <(const number& number2)
	{
		if (this->positive ^ number2.positive)
			return this->positive ? false : true;

		return this->positive ? absLess(number2) : number2.absLess(*this);
	}

	number reverse()
	{
		number newNumber;
		newNumber.positive = this->positive;

		auto tail = this->num;
		while (tail->next)
			tail = tail->next;

		while (tail)
		{
			newNumber.headInsert(tail->val);
			tail = tail->pre;
		}

		newNumber.cleanInvalidDigit();
		
		return newNumber;
	}
};

class Solution {
public:
	int reverse(int x) {
		number n1(x);

		return -1;
	}
};

int main()
{
	Solution s;
	cout << s.reverse(12345) << endl;
}