#include <stdio.h>

// ɾ��������N���ڵ�

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
		
		// rear���ƶ�nλ�� rear�Ƶ�null��ʱ�� front���ƶ����˱�ɾ���ڵ�ǰһ�ڵ�
		// ̫���� ֻ�ƶ�һ��
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