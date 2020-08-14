/*
��������?�ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ���?����?�ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢?һλ?���֡�

��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�

�����Լ���������� 0 ֮�⣬���������������� 0?��ͷ��

ʾ����

���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807

���룺(2 -> 4 -> 3) + (5 -> 6 -> 4 -> 1)
�����7 -> 0 -> 8 -> 1
ԭ��342 + 1465 = 1807

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/add-two-numbers
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include <stdio.h>
#include <algorithm>
#include <string>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p = l1;
		ListNode *q = l2;

		int count = 0;
		int k = 0;
		while (p && q)
		{
			count += (p->val + q->val) * pow(10, k);
			p = p->next;
			q = q->next;
			k++;
		}
		while (p)
		{
			count += p->val * pow(10, k);
			p = p->next;
			k++;
		}
		while (q)
		{
			count += q->val * pow(10, k);
			q = q->next;
			k++;
		}

		ListNode *t = new ListNode(count % 10);
		ListNode *h = t;
		int temp = count / 10;
		while (temp > 0)
		{
			ListNode *s = new ListNode(temp % 10);
			h->next = s;
			h = h->next;
			temp = temp / 10;
		}
		return t;
	}
};

class Solution1 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p = l1;
		ListNode *q = l2;

		long count = 0;
		int k = 0;
		int temp = 0;
		bool flag = false;
		std::string str;
		while (p && q)
		{
			temp = p->val + q->val;
			if (flag) 
			{
				temp++;
			}
			if (temp >= 10) 
			{
				flag = true;
				str.push_back(temp % 10);
			}
			else 
			{
				flag = false;
				str.push_back(temp);
			}
			p = p->next;
			q = q->next;
			k++;
		}
		while (p)
		{
			temp = p->val;
			if (flag)
			{
				temp++;
			}
			if (temp >= 10)
			{
				flag = true;
				str.push_back(temp % 10);
			}
			else
			{
				flag = false;
				str.push_back(temp);
			}
			p = p->next;
			k++;
		}
		while (q)
		{
			temp = q->val;
			if (flag)
			{
				temp++;
			}
			if (temp >= 10)
			{
				flag = true;
				str.push_back(temp % 10);
			}
			else
			{
				flag = false;
				str.push_back(temp);
			}
			q = q->next;
			k++;
		}
		if (flag)
		{
			str.push_back(1);
			k++;
		}

		printf("szdata:%s\n", str.c_str());

		ListNode *t = new ListNode(str[0]);
		ListNode *h = t;
		for (int i = 1; i< k; ++i)
		{
			ListNode *s = new ListNode(str[i]);
			h->next = s;
			h = h->next;
		}

		return t;
	}
};

#if defined(__LETCODE2__)
void main() 
{
	/*
	ListNode* l1 = new ListNode(2);
	ListNode* l11 = l1;
	ListNode* s = new ListNode(4);
	l11->next = s;
	l11 = l11->next;
	s = new ListNode(3);
	l11->next = s;
	l11 = l11->next;

	ListNode* l2 = new ListNode(5);
	ListNode* l22 = l2;
	s = new ListNode(6);
	l22->next = s;
	l22 = l22->next;
	s = new ListNode(4);
	l22->next = s;
	l22 = l22->next;
	s = new ListNode(1);
	l22->next = s;
	l22 = l22->next;
	*/

	ListNode* l1 = new ListNode(9);


	ListNode* l2 = new ListNode(1);
	ListNode* l22 = l2;
	ListNode *s = new ListNode(9);
	l22->next = s;
	l22 = l22->next;
	s = new ListNode(9);
	l22->next = s;
	l22 = l22->next;
	s = new ListNode(9);
	l22->next = s;
	l22 = l22->next;

	Solution1 solution;
	ListNode * h = solution.addTwoNumbers(l1, l2);
	while (h) 
	{
		printf("h->val:%d\n", h->val);
		h = h->next;
	}
	
}
#endif