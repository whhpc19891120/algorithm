/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例 :

输入: [-2, 1, -3, 4, -1, 2, 1, -5, 4],
	输出 : 6
	解释 : 连续子数组  [4, -1, 2, 1] 的和最大，为 6。
	进阶 :

	如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) 
	{
		// 暴力破解
		int max = INT_MIN; // 重要
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

	// 动态规划
	int maxSubArray1(vector<int> &nums)
	{
		// 类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
		int result = INT_MIN;
		int numsSize = int(nums.size());
		//dp[i]表示nums中以nums[i]结尾的最大子序和
		vector<int> dp(numsSize);
		dp[0] = nums[0]; // 初始状态
		result = dp[0];
		for (int i = 1; i < numsSize; i++)
		{
			// 这一句非常重要 比较i-1结尾 + 第i个节点的位置 与第i个节点的位置的值
			// 转移方程(*)
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			result = max(result, dp[i]);
		}
		return result;
	}

	// 动态规划(空间优化)
	int maxSubArray2(vector<int> &nums)
	{
		//类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
		int result = INT_MIN;
		int numsSize = int(nums.size());
		//dp[i]表示nums中以nums[i]结尾的最大子序和
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