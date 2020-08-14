#include <vector>
#include <algorithm>

using namespace std;

/*
题目：给你 k 种面值的硬币，面值分别为 c1, c2 ... ck，再给一个总金额 n，问你最少需要几枚硬币凑出这个金额，如果不可能凑出，则回答 - 1 。
比如说，k = 3，面值分别为 1，2，5，总金额 n = 11，那么最少需要 3 枚硬币，即 11 = 5 + 5 + 1 。下面走流程。
*/
class Solution
{
public:
	// 暴力递归
	int coinChange(vector<int>& coins, int amount)
	{
		if (amount == 0) return 0;
		int ans = INT_MAX;
		for (int coin : coins) 
		{
			// 金额不可达 (为什么是a-b < 0)
			if (amount - coin < 0) continue;

			// 下面三句组成状态转移方程(f(n) = min(f(n-c)) + 1) // 重要
			int subProb = coinChange(coins, amount - coin);
			// 子问题无解
			if (subProb == -1) continue;
			ans = min(ans, subProb + 1);
		}
		return ans == INT_MAX ? -1 : ans;
	}


	// 带备忘录的递归
	int coinChange2(vector<int>& coins, int amount) 
	{
		// 备忘录初始化为 -2
		vector<int> memo(amount + 1, -2);
		return helper(coins, amount, memo);
	}
	
	int helper(vector<int>& coins, int amount, vector<int>& memo) {
		if (amount == 0) return 0;
		if (memo[amount] != -2) return memo[amount];
		int ans = INT_MAX;
		for (int coin : coins) {
			// 金额不可达
			if (amount - coin < 0) continue;
			int subProb = helper(coins, amount - coin, memo);
			// 子问题无解
			if (subProb == -1) continue;
			ans = min(ans, subProb + 1);
		}
		// 记录本轮答案
		memo[amount] = (ans == INT_MAX) ? -1 : ans;
		return memo[amount];
	}

	// 动态规划
	int coinChange3(vector<int>& coins, int amount) 
	{
		// 动态规划
		vector<int> dp(amount + 1, amount + 1);
		dp[0] = 0;
		for (int i = 1; i <= amount; i++) 
		{
			for (int coin : coins)
				if (coin <= i)
					dp[i] = min(dp[i], dp[i - coin] + 1);
		}
		return dp[amount] > amount ? -1 : dp[amount];
	}
};


#if defined(__LETCODE_53_2__)
void main() 
{
	vector<int> vect = { 1,2,5 };

	Solution solution;
	int count = solution.coinChange(vect, 11);
}
#endif