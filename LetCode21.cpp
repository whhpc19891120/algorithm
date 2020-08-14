#include <stdio.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode * h1 = l1;
		ListNode * h2 = l2;
		ListNode * h = new ListNode(0);//哑节点简化代码
		ListNode * t = h;
		while (h1 && h2)
		{
			if (h1->val > h2->val)
			{
				h->next = new ListNode(h2->val);
				h2 = h2->next;
				h = h->next;
			}
			else if (h1->val < h2->val)
			{
				h->next = new ListNode(h1->val);
				h1 = h1->next;
				h = h->next;
			}
			else
			{
				h->next = new ListNode(h1->val);
				h = h->next;
				h->next = new ListNode(h2->val);
				h = h->next;
				h1 = h1->next;
				h2 = h2->next;
			}
		}

		// h可以直接指向h1或者h2

		while (h1)
		{
			h->next = new ListNode(h1->val);
			h1 = h1->next;
			h = h->next;
		}

		while (h2)
		{
			h->next = new ListNode(h2->val);
			h2 = h2->next;
			h = h->next;
		}

		return t->next;
	}
};