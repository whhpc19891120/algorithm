
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
	int type; // 0 表示左节点 1 表示右节点
	int value;
	Node* left;
	Node* right;
};

// 输出
void Output(string &str, map<char, string> &codemap)
{
	// 输出
	int length = str.length();
	string result;
	for (int i = 0; i < length; ++i)
	{
		result += codemap[str[i]];
	}

	//printf("%s\n", result.c_str());
	cout << result << endl;
}

//生成赫夫曼树
Node * CreateTree(priority_queue<char, vector<char>, greater<char>> &que)
{
	// 优先级队列(取出两个值计算、然后放进优先级队列中、保证最前面的最小)
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

// 搜索树(前序遍历)  递归算法
void SearchTree(Node *node, map<char, string> &codemap)
{
	
}

class Demo
{
public:

	// 非静态成员函数可以操作静态成员变量与静态成员函数
	void PrintA() 
	{
		printf("A------%d\n", a);
		printf("A------%d\n", b); 
		PrintB();
	}

	// 静态成员函数不可以操作非静态成员变量与非静态成员函数(没有this指针)
	static void PrintB() 
	{
		//printf("%d\n", a); 错误
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


// 主函数
int main1() {

	string str("abbcccdddd");
	//getline(std::cin, str);

	// 自动根据key排序
	map<int, char> frequce =
	{
		{1, 'a'}, {2, 'b'}, {3, 'c'}, {4, 'd'}
	};

	// 获取key
	priority_queue<char, vector<char>, greater<char>> que; // 采用优先级队列
	map<int, char>::iterator pos = frequce.begin();
	for (; pos != frequce.end(); ++pos)
	{
		que.push(pos->second);
	}

	// 创建
	Node * node = CreateTree(que);

	// 搜索
	map<char, string> codemap;
	SearchTree(node, codemap);

	// 输出
	Output(str, codemap);
}