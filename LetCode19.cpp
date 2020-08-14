#include <stdio.h>

// 删除倒数第N个节点

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* front = head;
		ListNode* rear = head;
		if (head->next == NULL) return NULL;
		
		// rear先移动n位， rear移到null的时候 front就移动到了被删除节点前一节点
		// 太棒了 只移动一次
		while (n-- >= 0) 
		{
			if (rear == NULL) return head->next;
			rear = rear->next;
		}
		while (rear) 
		{
			rear = rear->next;
			front = front->next;
		}
		front->next = front->next->next;
		return head;
	}
};