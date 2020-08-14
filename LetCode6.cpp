/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行?Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING"?行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例?1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例?2:

输入: s = "LEETCODEISHIRING", numRows =?4
输出:?"LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
*/


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	string convert(string s, int numRows) 
	{
		// 我的思路、考虑到了列的存储、实际上可以不考虑列的存储、直接顺序加到某一行后面（*）
		if (numRows == 1) 
			return s;

		vector<string> rows(min(numRows, int(s.size()))); // 防止s的长度小于行数
		int curRow = 0;
		bool goingDown = false;

		for (char c : s) 
		{
			rows[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1) 
			{// 当前行curRow为0或numRows -1时，箭头发生反向转折
				goingDown = !goingDown;
			}
			curRow += goingDown ? 1 : -1;
		}

		string ret;
		for (string row : rows) 
		{// 从上到下遍历行
			ret += row;
		}

		return ret;
	}
};