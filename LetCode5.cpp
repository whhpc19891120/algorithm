/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 ? s 的最大长度为 1000。

示例 1：

输入 : "babad"
	输出 : "bab"
	注意 : "aba" 也是一个有效答案。
	示例 2：

	输入 : "cbbd"
	输出 : "bb"

	来源：力扣（LeetCode）
	链接：https ://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	// 暴力破解法(效率太低)
	string longestPalindrome1(string s) 
	{
		string res = "";//存放结果
		string temp = "";//存放子串
		for (int i = 0; i < s.length(); i++)
		{
			for (int j = i; j < s.length(); j++)
			{
				temp = temp + s[j];
				string tem = temp;//tem存放子串反转结果
				std::reverse(tem.begin(), tem.end());//反转
				if (temp == tem)
					res = res.length() > temp.length() ? res : temp;
			}
			temp = "";
		}
		return res;
	}

	// 翻转求最大公共子串 并判断是否回文(仍旧会超过时间限制)
	string longestPalindrome2(string s) 
	{	
		//大小为1的字符串必为回文串
		if (s.length() == 1) 
			return s;
		//rev存放s反转结果
		string rev = s;
		//存放结果
		string res;
		std::reverse(rev.begin(), rev.end());
		if (rev == s) 
			return s;
		//存放回文子串的长度
		int len = 0;
		//查找s与rev的最长公共子串
		for (int i = 0; i < s.length(); i++)
		{
			string temp;//存放待验证子串
			for (int j = i; j < s.length(); j++)
			{
				temp = temp + s[j];
				if (rev.find(temp) != -1)
				{
					//q用来验证temp是否是回文子串
					string q = temp;
					std::reverse(q.begin(), q.end());
					if (q == temp)
					{
						len = temp.length();
						res = temp;
					}
				}
				else break;
			}
			temp = "";
		}
		return res;
	}

	// 动态规划（响应时间太长 Do not AC）
	string longestPalindrome3(string s)
	{
		int length = s.size();
		if (length == 0 || length == 1)
			return s;

		//定义二维动态数组
		vector<vector<int>>  dp(length, vector<int>(length));
		int maxLen = 0;
		string maxPal = "";
		for (int len = 1; len <= len; len++) 
		{
			//遍历所有的长度
			for (int start = 0; start < length; start++)
			{
				int end = start + len - 1;
				if (end >= length) //下标已经越界，结束本次循环
					break;
				dp[start][end] = (len == 1 || len == 2 || dp[start + 1][end - 1]) && s[start] == s[end]; //长度为 1 和 2 的单独判断下
				if (dp[start][end] && len > maxLen) 
				{
					maxPal = s.substr(start, end + 1);
				}
			}
		}
		return maxPal;
	}

	// 动态规划（AC 效率低下）
	string longestPalindrome4(string s) 
	{
		int len = s.size();
		if (len == 0 || len == 1)
			return s;
		int start = 0;//回文串起始位置
		int max = 1;//回文串最大长度
		vector<vector<int>>  dp(len, vector<int>(len));//定义二维动态数组
		for (int i = 0; i < len; i++)//初始化状态
		{
			dp[i][i] = 1;
			if (i < len - 1 && s[i] == s[i + 1])
			{
				dp[i][i + 1] = 1;
				max = 2;
				start = i;
			}
		}
		for (int l = 3; l <= len; l++)//l表示检索的子串长度，等于3表示先检索长度为3的子串
		{
			for (int i = 0; i + l - 1 < len; i++)
			{
				int j = l + i - 1;//终止字符位置
				if (s[i] == s[j] && dp[i + 1][j - 1] == 1)//状态转移
				{
					dp[i][j] = 1;
					start = i;
					max = l;
				}
			}
		}
		return s.substr(start, max);//获取最长回文子串
	}

	// 中心扩散法
	string longestPalindrome(string s) 
	{
		int len = s.size();
		if (len == 0 || len == 1)
			return s;
		int start = 0;//记录回文子串起始位置
		int end = 0;//记录回文子串终止位置
		int mlen = 0;//记录最大回文子串的长度
		for (int i = 0; i < len; i++)
		{
			int len1 = expendaroundcenter(s, i, i);//一个元素为中心
			int len2 = expendaroundcenter(s, i, i + 1);//两个元素为中心
			mlen = max(max(len1, len2), mlen);
			if (mlen > end - start + 1)
			{
				start = i - (mlen - 1) / 2;
				end = i + mlen / 2;
			}
		}
		return s.substr(start, mlen);
		//该函数的意思是获取从start开始长度为mlen长度的字符串
	}
private:

	//计算以left和right为中心的回文串长度
	int expendaroundcenter(string s, int left, int right)
	{
		int L = left;
		int R = right;
		while (L >= 0 && R < s.length() && s[R] == s[L])
		{
			L--;
			R++;
		}
		return R - L - 1;
	}	
};