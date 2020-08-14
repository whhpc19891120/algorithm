#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:

	// ·å¹È·¨
	int maxProfit(vector<int>& prices)
	{
		int i = 0;
		int valley = prices[0];
		int peak = prices[0];
		int maxprofit = 0;
		while (i < prices.size() - 1) 
		{
			while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
				i++;
			valley = prices[i];
			while (i < prices.size() - 1 && prices[i] <= prices[i + 1])
				i++;
			peak = prices[i];
			maxprofit += peak - valley;
		}
		return maxprofit;
	}

	// Ì°ÐÄËã·¨
	int maxProfit1(vector<int>& prices) 
	{
		int profit = 0;
		for (int i = 0; i + 1 < prices.size(); ++i) 
			profit += max(prices[i + 1] - prices[i], 0);
		return profit;
	}
	
	
};