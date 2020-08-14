#include <vector>

using namespace std;

class Solution
{
public:
	// 斐波拉契数列暴力解法
	int func(int n)
	{
		if (n == 0 || n == 1)
			return 1;
		else
			return func(n - 1) + func(n - 2);
	}

	// 带备忘录的递归
	int func1(int n) 
	{
		if (n < 1) return 0;
		vector<int> vect(n+1, 0); // 此处需要n+1 不然会越界
		help(vect, n);
	}

	int help(vector<int> &vect, int n) 
	{
		if (n == 0 || n == 1)
			return 1;
		if (vect[n] != 0)
			return vect[n];
		else
			vect[n] = help(vect, n - 1) + help(vect, n - 2);
		return vect[n];
	}

	// 动态规划
	int fun2(int n) 
	{
		if (n < 2)
			return 1;
		vector<int> dp(n + 1, 0);
		dp[0] = dp[1] =  1;
		for (int i = 2 ; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}


	// 动态规划(缩小空间)
	int fun3(int n)
	{
		if (n < 2)
			return 1;
		int previous = 1; // 最后一个前一个
		int last = 1; // 最后一个
	
		int sum = 0;
		for (int i = 2; i <= n; i++)
		{
			sum = previous + last;
			previous = last;
			last = sum;
		}
		return sum;
	}
};