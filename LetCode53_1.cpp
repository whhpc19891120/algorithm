#include <vector>

using namespace std;

class Solution
{
public:
	// 쳲��������б����ⷨ
	int func(int n)
	{
		if (n == 0 || n == 1)
			return 1;
		else
			return func(n - 1) + func(n - 2);
	}

	// ������¼�ĵݹ�
	int func1(int n) 
	{
		if (n < 1) return 0;
		vector<int> vect(n+1, 0); // �˴���Ҫn+1 ��Ȼ��Խ��
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

	// ��̬�滮
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


	// ��̬�滮(��С�ռ�)
	int fun3(int n)
	{
		if (n < 2)
			return 1;
		int previous = 1; // ���һ��ǰһ��
		int last = 1; // ���һ��
	
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