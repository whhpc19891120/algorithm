/*
����һ�����飬���ĵ�?i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�

��������ֻ�������һ�ʽ��ף������������һ֧��Ʊ�������һ���㷨�����������ܻ�ȡ���������

ע���㲻���������Ʊǰ������Ʊ��

ʾ�� 1:

����: [7,1,5,3,6,4]
���: 5
����: �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6-1 = 5 ��
	 ע���������� 7-1 = 6, ��Ϊ�����۸���Ҫ��������۸�
ʾ�� 2:

����: [7,6,4,3,1]
���: 0
����: �����������, û�н������, �����������Ϊ 0��
*/

/*
����һ���������������͵����⡣
��ͬѧ���ʣ�������ô�������ģ���Ϊ��������������Ĳ������֮�����ת����������⡣
Ҳ���㻹��һ���£�����ô��ĵ��������ѧ���ߵ���ѧ����ţ��������Ĺ�ʽ��ӡ��Ļ���


ֻ�������������F() �������������ģ�������ɢ���ģ�aa �� bb ��ʾ������±ꡣ�����ⲻӰ�����ǵó���ȷ�Ľ��ۡ�

�ܽ��£�����Ϳ���ת�����������⣬������⣬Ҳ����ת��������͵����⡣

������Ĺ�ʽ�У����ǰ� F()F() ��ʾ�������Ϊǰ׺�͡�

�������������Ϳ���ʹ�ö�̬�滮��⣬ dp[i]dp[i] ��ʾ�� ii Ϊ��β���������������ͣ����ƹ�ʽΪ��

dp[i] = max(0, dp[i-1])
dp[i]=max(0,dp[i-1] + diff(i))

 ����һ�㣬F(x)ʵ������f(x)��ԭ�������ڱ����У�F(b)��F(a)�ֱ�������������㣬
 ����Ҫ����ߵĲ����F(b) - F(a) = sum(f(a), ....f(b))�� f(a), f(b)��F(x)�ĵ�������
 ��������Ӧ���ȶԹ�Ʊ�����󵼣���ǰ�����Ȼ��������������������͡�

������ֱ�Ӽ�������������������

*/

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:

	// �����ⷨ(�ҳ��������Ĳ�ֵ�����ֵ)
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

	// �����ɼ�(���в�ͨ��)
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

	// ����ջ�Ľⷨ
	int maxProfit3(vector<int>& prices) 
	{
		if (prices.empty())
			return 0;
		stack<int> s;
		int dif = 0;
		s.push(prices[0]);
		for (int i = 1; i < prices.size(); i++)
		{
			//���С�ڣ�ջ��Ԫ�أ���ջ��Ԫ�س�ջ��������ջ
			if (prices[i] < s.top())
			{
				s.pop();
				s.push(prices[i]);
			}
			//�������ջ��Ԫ�أ�������ֵ�����Ƚϡ�
			else if (prices[i] > s.top())
				dif = ((prices[i] - s.top()) > dif) ? (prices[i] - s.top()) : dif;
		}
		return dif;
	}

	// ��̬�滮
	int maxProfit4(vector<int>& prices) 
	{
		if (prices.size() <= 1) 
			return 0;
		
		// ����ÿ��Ԫ��֮��Ĳ�ֵ
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
			// ״̬ת�Ʒ��� dp[i] = max(0, dp[i - 1] + diff[i]);
			dp[i] = max(0, dp[i - 1] + diff[i]);
			profit = max(profit, dp[i]);
		}
		return profit;
	}


	// ��̬�滮 dp���Ż���
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

	// ��̬�滮 diff���鱻�Ż���
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