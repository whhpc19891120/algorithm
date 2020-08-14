#include <vector>
#include <algorithm>

using namespace std;

/*
��Ŀ������ k ����ֵ��Ӳ�ң���ֵ�ֱ�Ϊ c1, c2 ... ck���ٸ�һ���ܽ�� n������������Ҫ��öӲ�Ҵճ��������������ܴճ�����ش� - 1 ��
����˵��k = 3����ֵ�ֱ�Ϊ 1��2��5���ܽ�� n = 11����ô������Ҫ 3 öӲ�ң��� 11 = 5 + 5 + 1 �����������̡�
*/
class Solution
{
public:
	// �����ݹ�
	int coinChange(vector<int>& coins, int amount)
	{
		if (amount == 0) return 0;
		int ans = INT_MAX;
		for (int coin : coins) 
		{
			// ���ɴ� (Ϊʲô��a-b < 0)
			if (amount - coin < 0) continue;

			// �����������״̬ת�Ʒ���(f(n) = min(f(n-c)) + 1) // ��Ҫ
			int subProb = coinChange(coins, amount - coin);
			// �������޽�
			if (subProb == -1) continue;
			ans = min(ans, subProb + 1);
		}
		return ans == INT_MAX ? -1 : ans;
	}


	// ������¼�ĵݹ�
	int coinChange2(vector<int>& coins, int amount) 
	{
		// ����¼��ʼ��Ϊ -2
		vector<int> memo(amount + 1, -2);
		return helper(coins, amount, memo);
	}
	
	int helper(vector<int>& coins, int amount, vector<int>& memo) {
		if (amount == 0) return 0;
		if (memo[amount] != -2) return memo[amount];
		int ans = INT_MAX;
		for (int coin : coins) {
			// ���ɴ�
			if (amount - coin < 0) continue;
			int subProb = helper(coins, amount - coin, memo);
			// �������޽�
			if (subProb == -1) continue;
			ans = min(ans, subProb + 1);
		}
		// ��¼���ִ�
		memo[amount] = (ans == INT_MAX) ? -1 : ans;
		return memo[amount];
	}

	// ��̬�滮
	int coinChange3(vector<int>& coins, int amount) 
	{
		// ��̬�滮
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