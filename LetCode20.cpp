// ��Ч������

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) 
	{
		if (s.empty()) return true;
		// ����һ��ջ
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