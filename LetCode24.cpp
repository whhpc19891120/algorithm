#include <stdio.h>

// 给定 1->2->3->4, 你应该返回 2->1->4->3.

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

	// 不理解(如何才能熟练的写出来)
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL) 
			return head;
		auto p1 = head;
		auto p2 = p1->next;
		p1->next = swapPairs(p2->next);
		p2->next = p1;
		return p2;
	}

	// 增加伪节点、减少复杂度
	ListNode* swapPairs2(ListNode* head) {
		ListNode *res = new ListNode(0), *tmp = res;
		res->next = head;
		while (tmp->next != NULL && tmp->next->next != NULL) {
			ListNode *start = tmp->next, *end = tmp->next->next;
			tmp->next = end;
			start->next = end->next;
			end->next = start;
			tmp = start;
		}
		return res->next;
	}
};