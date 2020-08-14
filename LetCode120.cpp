/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

[
	[2],
	[3, 4],
	[6, 5, 7],
	[4, 1, 8, 3]
]
自顶向下的最小路径和为 ? 11（即，2 ? +? 3 ? +? 5 ? +? 1 ? = 11）。

说明：

如果你可以只使用 O(n) ? 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	// 动态规划 自底向上
	/*
	   状态转移方程 设状态为f(i,i) 为从位置(i, j)出发最小路径和、则状态转移方程为
	   递推式 dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
	*/
	int minimumTotal1(vector<vector<int>>& triangle)
	{
		// 动态规划, 自底向上  
		int rowSize = triangle.size();
		vector<vector<int>> dp(triangle);

		// 从倒数第二行开始
		for (int i = rowSize - 2; i >= 0; i--) 
		{
			// 例如从第i行开始 则有i列
			for (int j = 0; j < triangle[i].size(); j++) 
			{
				dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return dp[0][0];
	}

	// 动态规划 自底向上(为minimumTotal1空间上的优化)
	/*
	   状态转移方程 设状态为f(i,i) 为从位置(i, j)出发最小路径和、则状态转移方程为
       f(i, j) = min {f(i + 1, j), f(i + 1, j + 1)} + (i, j)
	*/
	int minimumTotal2(vector<vector<int>>& triangle) 
	{
		// 自底向上
		int n = triangle.size();
		// 以最后一行数组为初始化状态
		vector<int> dp(triangle[n - 1]);
		// 从倒数第二行开始
		for (int i = n - 2; i >= 0; i--)
			// 例如从第三行开始 则有三列
			for (int j = 0; j <= i; j++)
				// dp[j] 表示从i行开始的最小路径(dp数组会被每行都复用)
				dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
		return dp[0];
	}

	// 动态规划 自顶向下
	int minimumTotal3(vector<vector<int>>& triangle)
	{
		// 自顶向下
		int row = triangle.size();  //总行数
		vector<int> dp(row, INT_MAX);   //创建一个O(n)的数组,初值为INT_MAX(同样会被每一行复用)
		dp[0] = triangle[0][0];

		int temp = 0;
		int t = INT_MAX;

		for (int i = 1; i < row; i++)
		{
			temp = INT_MAX;
			for (int j = 0; j <= i; j++)
			{
				t = dp[j];  //保存下来，下一轮使用
				dp[j] = min(temp, dp[j]) + triangle[i][j];  //每次跟triangle[i-1][j-1],triangle[i-1][j]中的最小值相加
				temp = t; //temp表示上一轮dp[j]的值即triangle[i-1][j-1] 
			}
		}

		auto Min = min_element(begin(dp), end(dp));
		return  *Min;
	}
};


#if defined(__LETCODE_120__)
int main()
{
	vector<vector<int>> triangle;
	triangle.push_back({ 2 });
	triangle.push_back({ 3,4 });
	triangle.push_back({ 6,5,7 });
	triangle.push_back({ 4,1,8,3 });


	Solution solution;
	solution.minimumTotal3(triangle);
}
#endif