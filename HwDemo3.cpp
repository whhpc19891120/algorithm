
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Node
{
	int type; // 0 ��ʾ��ڵ� 1 ��ʾ�ҽڵ�
	int value;
	Node* left;
	Node* right;
};

// ���
void Output(string &str, map<char, string> &codemap)
{
	// ���
	int length = str.length();
	string result;
	for (int i = 0; i < length; ++i)
	{
		result += codemap[str[i]];
	}

	//printf("%s\n", result.c_str());
	cout << result << endl;
}

//���ɺշ�����
Node * CreateTree(priority_queue<char, vector<char>, greater<char>> &que)
{
	// ���ȼ�����(ȡ������ֵ���㡢Ȼ��Ž����ȼ������С���֤��ǰ�����С)
	int left = 0;
	int right = 0;
	Node * root = nullptr;
	while (que.size() > 1)
	{
		left = que.top();
		que.pop();
		Node * node1 = new Node();

		right = que.top();
		que.pop();
		Node * node2 = new Node();

		que.push(left + right);
	}
	return nullptr;
}

// ������(ǰ�����)  �ݹ��㷨
void SearchTree(Node *node, map<char, string> &codemap)
{
	
}

class Demo
{
public:

	// �Ǿ�̬��Ա�������Բ�����̬��Ա�����뾲̬��Ա����
	void PrintA() 
	{
		printf("A------%d\n", a);
		printf("A------%d\n", b); 
		PrintB();
	}

	// ��̬��Ա���������Բ����Ǿ�̬��Ա������Ǿ�̬��Ա����(û��thisָ��)
	static void PrintB() 
	{
		//printf("%d\n", a); ����
		printf("B---------%d\n", b);
	}

private:
	int a = 2;
	static int b;
};

int Demo::b = 1;

int main() 
{
	Demo d;
	d.PrintA();
	d.PrintB();
}


// ������
int main1() {

	string str("abbcccdddd");
	//getline(std::cin, str);

	// �Զ�����key����
	map<int, char> frequce =
	{
		{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}
	};

	// ��ȡkey
	priority_queue<char, vector<char>, greater<char>> que; // �������ȼ�����
	map<int, char>::iterator pos = frequce.begin();
	for (; pos != frequce.end(); ++pos)
	{
		que.push(pos->second);
	}

	// ����
	Node * node = CreateTree(que);

	// ����
	map<char, string> codemap;
	SearchTree(node, codemap);

	// ���
	Output(str, codemap);
}