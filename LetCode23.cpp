#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

	// ��һ���͵ڶ����ϲ�֮����ȥ�ϲ�������-------->
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int size = lists.size();
		if (size == 0) {
			return nullptr;
		}
		if (size == 1) {
			return lists[0];
		}
		ListNode *p = lists[0];
		for (int i = 1; i < size; ++i) {
			p = merge(p, lists[i]);
		}
		return p;
	}
	ListNode* merge(ListNode *l1, ListNode *l2) {
		ListNode *head = new ListNode(0);
		ListNode *p = head;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
			}
			else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		p->next = l1 ? l1 : l2; //ֱ�ӹ�������
		return head->next;
	}


	ListNode* mergeKLists2(vector<ListNode*>& lists) {
		int size = lists.size();
		if (size == 0) {
			return nullptr;
		}
		if (size == 1) {
			return lists[0];
		}
		queue<ListNode*> waiting(deque<ListNode*>(lists.begin(), lists.end())); //��vectorתΪ����
		//�������Ԫ�ش���1����ȡ���������кϲ����ϲ�������������ӵ�����β��
		while (waiting.size() > 1) {
			ListNode *l1 = waiting.front();
			waiting.pop();
			ListNode *l2 = waiting.front();
			waiting.pop();
			waiting.push(merge2(l1, l2));
		}
		return waiting.front();
	}
	ListNode* merge2(ListNode *l1, ListNode *l2) {
		ListNode *head = new ListNode(0);
		ListNode *p = head;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
			}
			else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		p->next = l1 ? l1 : l2;
		return head->next;
	}
};