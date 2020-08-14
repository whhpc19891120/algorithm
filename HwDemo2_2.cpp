#include <string>
#include <vector>

using namespace std;

//动态规划求解：
//用dp[s.length() + 1]表示字符串s的解码方式

int numDecodings(string s) 
{
	int len = s.length();
	if (len == 0 || s[0] == '0') 
	{
		return 0;
	}

	vector<int> dp(len + 1, 0);   //dp[i]表示s[i-1]有多少种编码
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= len; i++) 
	{
		if (s[i - 1] >= '1'&&s[i - 1] <= '9') 
		{
			dp[i] += dp[i - 1];
		}
		// 从左至右 && 优先级大于 ||
		if ((s[i - 2] == '1' || s[i - 2] == '2') && s[i - 1] >= '0' && s[i - 1] <= '6') 
		{
			dp[i] += dp[i - 2];
		}
	}
	return dp[len];
}


int numDecodings1(const string &s)
{
	if (s.empty() || s[0] == '0') return 0;
	int prev = 0;
	int cur = 1;
	for (size_t i = 1; i <= s.size(); ++i) {
		if (s[i - 1] == '0') cur = 0;
		if (i < 2 || !(s[i - 2] == '1' ||
			(s[i - 2] == '2' && s[i - 1] <= '6')))
			prev = 0;
		int tmp = cur;
		cur = prev + cur;
		prev = tmp;
	}
	return cur;
}