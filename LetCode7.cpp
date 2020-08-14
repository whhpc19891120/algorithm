/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例?1:

输入: 123
输出: 321
?示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为?[?231,? 231?? 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

*/

#include <string>

using namespace std;

class Solution {
public:
	int reverse(int x) 
	{
		int y = x > 0 ? x : x * -1;
		if (x == 0)
			return 0;

		// 去掉末尾0
		while (y%10 == 0) 
		{
			y = y / 10;
		}
		string str = to_string(y);
		std::reverse(str.begin(), str.end());
		string strlimit = to_string((int)pow(2, 32) - 1);
		if (str.length() == strlimit.length() && str > strlimit )
		{
			return 0;
		}
		int k = atoi(str.c_str());
		if (x < 0) 
		{
			k = k * -1;
		}
		return k;
	}
};

#if defined(__LETCODE7__)
void main() 
{
	Solution solution;
	solution.reverse(8);
}
#endif