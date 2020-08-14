// 有效的括号

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) 
	{
		if (s.empty()) return true;
		// 定义一个栈
		std::stack<char> stk;
		char c = 0;
		for (size_t i = 0; i< s.length(); ++i)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				stk.push(s[i]);
			}
			else if (s[i] == ')')
			{
				if (!stk.empty() && stk.top() == '(') stk.pop();
				else stk.push(s[i]);
			}
			else if (s[i] == ']') 
			{
				if (!stk.empty() && stk.top() == '[') stk.pop();
				else stk.push(s[i]);
			}
			else if (s[i] == '}')
			{
				if (!stk.empty() && stk.top() == '{') stk.pop();
				else stk.push(s[i]);
			}
		}

		return stk.empty();
	}
};