#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
返回符合要求的最少分割次数。
示例:
输入: "aab"
输出: 1
解释: 进行一次分割就可将s 分割成 ["aa","b"] 这样两个回文子串。
*/

/*
我做这题的时候还没有太详细的题解，我这里就先做一下吧。
我这个的思想来自于美区@nraptis的评论

此题动态规划开了一个数组list，list[i]代表前i个字符需要划分几次，数组长度为l+1（l为字符串s的长度），
初始化为[-1, 0, 1,..., n-1]（规定前0个字符需要-1次）

然后从i = range(l)循环一次，每次以s[i]为中心寻找回文子串，当找到从start到end为回文串时，

设置list[end+1]=min(list[start]+1, list[end+1])
如果这是回文串，那么到这里为止的划分次数可以为这个回文串前面所需的次数+1）

比如"ggbobanabob"：

[Initial] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
[Loop 0] { 0, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10} //g
[Loop 1] { 0, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10} //g
[Loop 2] { 0, 0, 1, 3, 4, 5, 6, 7, 8, 9, 10} //b
[Loop 3] { 0, 0, 1, 2, 1, 5, 6, 7, 8, 9, 10} //o
[Loop 4] { 0, 0, 1, 2, 1, 5, 6, 7, 8, 9, 10} //b
[Loop 5] { 0, 0, 1, 2, 1, 2, 6, 7, 8, 9, 10} //a
[Loop 6] { 0, 0, 1, 2, 1, 2, 3, 2, 3, 2, 1} //n
*/

class Solution 
{
public:
	int minCut(string s)
	{
		int l = s.length();
		vector<int> list(l + 1); // list[i]代表前i个字符需要划几次，特别地，list[0]=-1
		for (int i = 0; i < l + 1; ++i) 
		{ // 初始化[-1, 0, 1, 2, 3...]
			list[i] = i - 1;
		}
		for (int i = 0; i < l; ++i) 
		{ // 以每个字符为中心找最长回文子串
			list[i + 1] = min(list[i + 1], list[i] + 1); // 初始化，最坏情况下就比左边的多划一次
			if (i == l - 1) 
			{ // 最后一个了没必要找了
				break;
			}
			// 先找偶数个的
			int start = i, end = i + 1;
			while (s[start] == s[end]) 
			{
				list[end + 1] = min(list[end + 1], list[start] + 1);
				if (end == l - 1 || start == 0) 
				{
					break;
				}
				--start, ++end;
			}
			// 再找奇数个的
			start = i - 1, end = i + 1;
			if (start < 0) 
			{
				continue;
			}
			while (s[start] == s[end]) 
			{
				list[end + 1] = min(list[end + 1], list[start] + 1);
				if (end == l - 1 || start == 0) 
				{
					break;
				}
				--start, ++end;
			}
			// 如果整个串都是回文串，那么就中断
			if (list[l] == 0) 
			{
				return 0;
			}
		}
		return list[l];
	}
};

#if defined(__LETCODE_132__)
void main() 
{
	int a[2][2] = { {1}, {2,3} };
	printf("%d\n", a[0][1]);

	char **s;
	char* str = (char *)"data";
	s = &str;

	Solution solution;
	solution.minCut("aab");
}
#endif 