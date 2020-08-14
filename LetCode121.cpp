/*
给定一个数组，它的第?i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
	 注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
*/

/*
这是一个最大连续子数组和的问题。
有同学会问，这是怎么看出来的，因为在数组中求两点的差，而两点之差可以转换成求和问题。
也许你还是一脸懵，这怎么想的到。如果你学过高等数学，对牛顿莱布尼茨公式有印象的话：


只不过，在我这里，F() 函数不是连续的，而是离散化的，aa 和 bb 表示数组的下标。但是这不影响我们得出正确的结论。

总结下：区间和可以转换成求差的问题，求差问题，也可以转换成区间和的问题。

在上面的公式中，我们把 F()F() 表示的数组称为前缀和。

最大连续子数组和可以使用动态规划求解， dp[i]dp[i] 表示以 ii 为结尾的最大连续子数组和，递推公式为：

dp[i] = max(0, dp[i-1])
dp[i]=max(0,dp[i-1] + diff(i))

 补充一点，F(x)实际上是f(x)的原函数。在本题中，F(b)和F(a)分别代表买入卖出点，
 我们要算二者的差，所以F(b) - F(a) = sum(f(a), ....f(b))。 f(a), f(b)是F(x)的导函数。
 所以这里应该先对股票序列求导，即前后做差，然后计算其连续子数组最大和。

而不是直接计算其连续子数组最大和

*/

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:

	// 暴力解法(找出两个数的差值的最大值)
	int maxProfit1(vector<int>& prices) {
		int maxprofit = 0;
		for (int i = 0; i < prices.size() - 1; i++) {
			for (int j = i + 1; j < prices.size(); j++) {
				int profit = prices[j] - prices[i];
				if (profit > maxprofit)
					maxprofit = profit;
			}
		}
		return maxprofit;
	}

	// 奇淫巧技(运行不通过)
	int maxProfit2(vector<int>& prices) {
		if (prices.empty()) return 0;
		int s1 = -prices[0], s2 = INT_MIN, s3 = INT_MIN, s4 = INT_MIN;

		for (int i = 1; i < prices.size(); ++i) {
			s1 = max(s1, -prices[i]);
			s2 = max(s2, s1 + prices[i]);
			s3 = max(s3, s2 - prices[i]);
			s4 = max(s4, s3 + prices[i]);
		}
		return max(0, s4);
	}

	// 利用栈的解法
	int maxProfit3(vector<int>& prices) 
	{
		if (prices.empty())
			return 0;
		stack<int> s;
		int dif = 0;
		s.push(prices[0]);
		for (int i = 1; i < prices.size(); i++)
		{
			//如果小于，栈顶元素，则栈顶元素出栈，该数入栈
			if (prices[i] < s.top())
			{
				s.pop();
				s.push(prices[i]);
			}
			//如果大于栈顶元素，则计算差值，并比较。
			else if (prices[i] > s.top())
				dif = ((prices[i] - s.top()) > dif) ? (prices[i] - s.top()) : dif;
		}
		return dif;
	}

	// 动态规划
	int maxProfit4(vector<int>& prices) 
	{
		if (prices.size() <= 1) 
			return 0;
		
		// 计算每个元素之间的差值
		vector<int> diff(prices.size() - 1);
		for (int i = 0; i < prices.size() - 1; ++i) 
		{
			diff[i] = prices[i + 1] - prices[i];
		}

		vector<int> dp(diff.size());
		dp[0] = max(0, diff[0]);
		int profit = dp[0];
		for (int i = 1; i < diff.size(); ++i) 
		{
			// 状态转移方程 dp[i] = max(0, dp[i - 1] + diff[i]);
			dp[i] = max(0, dp[i - 1] + diff[i]);
			profit = max(profit, dp[i]);
		}
		return profit;
	}


	// 动态规划 dp被优化掉
	int maxProfit5(vector<int>& prices) 
	{
		if (prices.size() <= 1) return 0;
		vector<int> diff(prices.size() - 1);
		for (int i = 0; i < prices.size() - 1; ++i) 
		{
			diff[i] = prices[i + 1] - prices[i];
		}

		int last = 0;
		int profit = last;
		for (int i = 0; i < diff.size(); ++i)
		{
			last = max(0, last + diff[i]);
			profit = max(profit, last);
		}
		return profit;
	}

	// 动态规划 diff数组被优化掉
	int maxProfit6(vector<int>& prices)
	{
		int last = 0, profit = 0;
		for (int i = 0; i < (int)prices.size() - 1; ++i) 
		{
			last = max(0, last + prices[i + 1] - prices[i]);
			profit = max(profit, last);
		}
		return profit;
	}
};

#if defined(__LETCODE_121__)
void main() 
{
	vector<int> vect = { 7,1,5,3,6,4 };

	Solution solution;
	solution.maxProfit4(vect);
}
#endif