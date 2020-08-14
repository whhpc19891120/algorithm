/*
给定一个字符串?S?和一个字符串?T，计算在 S 的子序列中 T 出现的个数。

一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE"?是?"ABCDE"?的一个子序列，而?"AEC"?不是）

示例?1:

输入: S = "rabbbit", T = "rabbit"
输出:?3
解释:

如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案。
(上箭头符号 ^ 表示选取的字母)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
示例?2:

输入: S = "babgbag", T = "bag"
输出:?5
解释:

如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案。
(上箭头符号 ^ 表示选取的字母)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
	^^^
*/


/*
状态表示：dp[i][j]表示d的前i个字符的子序列能组成t的前j个字符的方法数。
则最终结果应该为：dp[s.size()][t.size()]
状态转移：
对于dp[i][j]中s[i-1]和t[j-1]有两种情况：

s[i-1] == t[j-1]时，相等时，对于s[i-1]有两种处理方法:
(1)、将s[i-1]看作子序列的最后一个字符的情况下，其方法数等于s的前i-1能构成t的前j-1个的方法数dp[i-1][j-1]
(2)、不考虑s[i-1]时，剩余的s的前i-1个能构成t的前j个的方法数：dp[i-1][j]最终的方法数为两者相加：dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
s[i-1] != t[j-1]时，此时的方法数等价于移除s的第i个元素后，剩余的前i-1个元素的子序列能构成t的前j个元素的方法数：dp[i][j] = dp[i-1][j]
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) 
	{
		int n = s.size(), m = t.size();
		if (m == 0) return 1;
		if (n == 0) return 0;
		vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
		// dp[i][0] = 1, dp[0][j] = 0;
		for (int i = 0; i <= n; i++) dp[i][0] = 1;
		// 状态转移
		// s[i-1] == t[j-1]时，dp[i][j] = dp[i-1][j-1] + dp[i-1][j]  dp[i-1][j-1]表示保留s[i-1]的情况，dp[i-1][j]表示移除s[i-1]的情况
		// s[i-1] != t[j-1]时，dp[i][j] = dp[i-1][j]
		for (int i = 1; i <= n; i++) 
		{
			for (int j = 1; j <= m; j++) 
			{
				dp[i][j] = dp[i - 1][j];
				if (s[i - 1] == t[j - 1]) 
					dp[i][j] += dp[i - 1][j - 1];
			}
		}

		return dp[n][m];
	}
};
