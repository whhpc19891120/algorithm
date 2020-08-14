/*
给定三个字符串?s1, s2, s3, 验证?s3?是否是由?s1?和?s2 交错组成的。

示例 1:
输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出: true

示例 2:
输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出: false
*/


/*
维护一个(m+1)*(n+1)的dp
这是一个二维动规问题，可以看作s1的前i个字符和s2的前j个字符是否可以构成s3的前i+j个字符
注意因为要维护初始行和列，因此下标访问涉及一些调整
如果上一行为1且s1[i-1]等于s3[i+j-1]或者上一列为1且s2[j-1]等于s3[i+j-1]则dp[i][j]就为1，其他情况为0
初始化第一行和第一列时注意，dp[0][0]=1,因为空的s1和空的s2可以构成空的s3
*/

/*

*/

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:

	// 二维动态规划
	bool isInterleave(string s1, string s2, string s3) 
	{
		int N1 = s1.size();
		int N2 = s2.size();
		int N3 = s3.size();
		if (N1 + N2 != N3) return false;
		vector<vector<bool> > dp(N1 + 1, vector<bool>(N2 + 1, false));
		dp[0][0] = true;
		for (int i = 0; i <= N1; ++i) 
		{
			for (int j = 0; j <= N2; ++j) 
			{
				if (i > 0 && s1[i - 1] == s3[i + j - 1]) 
				{
					dp[i][j] = dp[i][j] || dp[i - 1][j];
				}
				if (j > 0 && s2[j - 1] == s3[i + j - 1]) 
				{
					dp[i][j] = dp[i][j] || dp[i][j - 1];
				}
			}
		}
		return dp[N1][N2];
	}

	// 一维动态规划
	bool isInterleave2(string s1, string s2, string s3) 
	{
		if (s3.length() != s1.length() + s2.length()) {
			return false;
		}
		vector<bool> dp(s2.length() + 1);
		for (int i = 0; i <= s1.length(); i++) 
		{
			for (int j = 0; j <= s2.length(); j++) 
			{
				if (i == 0 && j == 0) 
				{
					dp[j] = true;
				}
				else if (i == 0) 
				{
					dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
				}
				else if (j == 0) 
				{
					dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
				}
				else 
				{
					dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1] || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]));
				}
			}
		}
		return dp[s2.length()];
	}

};


#if defined(__LETCODE_97__)
void main() 
{
	Solution solution;
	solution.isInterleave("aabcc", "dbbca", "aadbbcbcac");
}
#endif