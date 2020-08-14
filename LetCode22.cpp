#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:

	/*
	为了生成所有序列，我们使用递归。长度为 n 的序列就是 '(' 加上所有长度为 n-1 的序列，以及 ')' 加上所有长度为 n-1 的序列。
    为了检查序列是否为有效的，我们会跟踪 平衡，也就是左括号的数量减去右括号的数量的净值。
	如果这个值始终小于零或者不以零结束，该序列就是无效的，否则它是有效的。
	*/

	// 暴力方法(X)
	vector<string> generateParenthesis1(int n) 
	{
		vector<string> combinations;
		string str;
		str.resize(2 * n);
		generateAll(str, 0, combinations);
		return combinations;

	}

	void generateAll(string str, int pos, vector<string> &result) {
		if (pos == str.length()) {
			if (valid(str))
				result.emplace_back(str);
		}
		else 
		{
			str[pos] = '(';
			generateAll(str, pos + 1, result);
			str[pos] = ')';
			generateAll(str, pos + 1, result);
		}
	}

	bool valid(string str) {
		int balance = 0;
		for (char c : str) {
			if (c == '(') balance++;
			else balance--;
			if (balance < 0) return false;
		}
		return (balance == 0);
	}


	/*
	闭合法理解:
算法: 递归关系 n对有效括号序列由c 对有效括号序列和 n-c对有效括号序列组成
n对有效括号序列 是由 "(" + $1 + ")" + $2 拼接而成, $1 表示c(0<=c<n)对有效括号序列集合中的某一个元素, 
$2表示剩下的n-1-c对有效括号序列构成的集合中的某一个元素. 这样说大致就能看懂程序在做什么了
这里要说一下为什么要ans.add("(" + left + ")" + right); 而不是ans.add(left+right)呢,
应该是因为有一种特殊的情况 如果left right(n=4) 全是()() 这种分隔的小括号 
则当(left,right)为(1,3)或者(2,2)或者(3,1) 就会出现()()()()重复出现多次的情况, 
而上面那种做法可以将()()()()的情况放到left=0,rigint=3的情况中,且只会出现一次, 非常nice
	*/
	// 闭合数
	vector<string> generateParenthesis2(int n)
	{
		vector<string> res;
		if (n == 0)  res.emplace_back("");
		for (int i = 0; i < n; i++)
			for (string left : generateParenthesis2(i))
				for (string right : generateParenthesis2(n - 1 - i))
					res.emplace_back("(" + left + ")" + right);
		return res;
	}

	// 利用left，right分别记录已经添加的左右括号的数目，简单回溯即可
	void backtrace(int left, int right, int n, string& s, vector<string>& res) {
		if (left == n && right == n) {
			res.push_back(s);
			return;
		}
		if (left < n) {
			s += "(";
			backtrace(left + 1, right, n, s, res);
			s.pop_back();
		}
		if (right < left) {
			s += ")";
			backtrace(left, right + 1, n, s, res);
			s.pop_back();
		}
	}
	vector<string> generateParenthesis3(int n) {
		vector<string> res;
		string s;
		backtrace(0, 0, n, s, res);
		return res;
	}
};

#if defined(_LETCODE22_)
void main()
{
	Solution solution;
	vector<string> result = solution.generateParenthesis1(2);
}
#endif