/*
����һ���������� nums ���ҵ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

ʾ�� :

����: [-2, 1, -3, 4, -1, 2, 1, -5, 4],
	��� : 6
	���� : ����������  [4, -1, 2, 1] �ĺ����Ϊ 6��
	���� :

	������Ѿ�ʵ�ָ��Ӷ�Ϊ O(n) �Ľⷨ������ʹ�ø�Ϊ����ķ��η���⡣
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) 
	{
		// �����ƽ�
		int max = INT_MIN; // ��Ҫ
		int sum = 0;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			sum = 0;
			for (size_t j = i; j < nums.size(); ++j)
			{
				sum += nums[j];
				if (sum > max)
					max = sum;
			}
		}
		return max;
	}

	// ��̬�滮
	int maxSubArray1(vector<int> &nums)
	{
		// ����Ѱ�������Сֵ����Ŀ����ʼֵһ��Ҫ����������ϵ���С���ֵ
		int result = INT_MIN;
		int numsSize = int(nums.size());
		//dp[i]��ʾnums����nums[i]��β����������
		vector<int> dp(numsSize);
		dp[0] = nums[0]; // ��ʼ״̬
		result = dp[0];
		for (int i = 1; i < numsSize; i++)
		{
			// ��һ��ǳ���Ҫ �Ƚ�i-1��β + ��i���ڵ��λ�� ���i���ڵ��λ�õ�ֵ
			// ת�Ʒ���(*)
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			result = max(result, dp[i]);
		}
		return result;
	}

	// ��̬�滮(�ռ��Ż�)
	int maxSubArray2(vector<int> &nums)
	{
		//����Ѱ�������Сֵ����Ŀ����ʼֵһ��Ҫ����������ϵ���С���ֵ
		int result = INT_MIN;
		int numsSize = int(nums.size());
		//dp[i]��ʾnums����nums[i]��β����������
		int dp(nums[0]);
		result = dp;
		for (int i = 1; i < numsSize; i++)
		{
			dp = max(dp + nums[i], nums[i]);
			result = max(result, dp);
		}

		return result;
	}
};