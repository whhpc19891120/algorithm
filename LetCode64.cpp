
/*
给定一个包含非负整数的 m?x?n?网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	/*
	我们新建一个额外的 dpdp 数组，与原矩阵大小相同。在这个矩阵中，dp(i, j)dp(i,j) 表示从坐标 (i, j)(i,j) 到右下角的最小路径权值。
	我们初始化右下角的 dpdp 值为对应的原矩阵值，然后去填整个矩阵，对于每个元素考虑移动到右边或者下面，因此获得最小路径和我们有如下递推公式：
	dp(i,j)=grid(i,j)+min(dp(i+1,j),dp(i,j+1))

	*/
	// 二维动态规划(从下至上)
	int minPathSum(vector<vector<int>>& grid) 
	{
		vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));
		for (int i = grid.size() - 1; i >= 0; i--) 
		{
			for (int j = grid[0].size() - 1; j >= 0; j--) 
			{
				if (i == grid.size() - 1 && j != grid[0].size() - 1)
					dp[i][j] = grid[i][j] + dp[i][j + 1];
				else if (j == grid[0].size() - 1 && i != grid.size() - 1)
					dp[i][j] = grid[i][j] + dp[i + 1][j];
				else if (j != grid[0].size() - 1 && i != grid.size() - 1)
					dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
				else
					dp[i][j] = grid[i][j];
			}
		}
		return dp[0][0];
	}

	/*
	在上个解法中，我们可以用一个一维数组来代替二维数组，dpdp 数组的大小和行大小相同。
这是因为对于某个固定状态，只需要考虑下方和右侧的节点。
首先初始化 dpdp 数组最后一个元素是右下角的元素值，然后我们向左移更新每个 dp(j)dp(j) 为：

dp(j)=grid(i,j)+min(dp(j),dp(j+1))

我们对于每一行都重复这个过程，然后向上一行移动，计算完成后 dp(0) 就是最后的结果。
	*/
	// 一维动态规划
	int minPathSum2(vector<vector<int>>& grid)
	{
		vector<int> dp(grid[0].size());
		for (int i = grid.size() - 1; i >= 0; i--)
		{
			for (int j = grid[0].size() - 1; j >= 0; j--)
			{
				if (i == grid.size() - 1 && j != grid[0].size() - 1)
					dp[j] = grid[i][j] + dp[j + 1];
				else if (j == grid[0].size() - 1 && i != grid.size() - 1)
					dp[j] = grid[i][j] + dp[j];
				else if (j != grid[0].size() - 1 && i != grid.size() - 1)
					dp[j] = grid[i][j] + min(dp[j], dp[j + 1]);
				else
					dp[j] = grid[i][j];
			}
		}
		return dp[0];
	}

	/*
	和方法 2 相同，惟一的区别是，不需要用额外的 dpdp 数组，而是在原数组上存储，这样就不需要额外的存储空间。递推公式如下：
	grid(i,j)=grid(i,j)+min(grid(i+1,j),grid(i,j+1))
	*/

	// 动态规划(原地修改)
	int minPathSum3(vector<vector<int>>& grid) 
	{
		for (int i = grid.size() - 1; i >= 0; i--) 
		{
			for (int j = grid[0].size() - 1; j >= 0; j--) 
			{
				if (i == grid.size() - 1 && j != grid[0].size() - 1)
					grid[i][j] = grid[i][j] + grid[i][j + 1];
				else if (j == grid[0].size() - 1 && i != grid.size() - 1)
					grid[i][j] = grid[i][j] + grid[i + 1][j];
				else if (j != grid[0].size() - 1 && i != grid.size() - 1)
					grid[i][j] = grid[i][j] + min(grid[i + 1][j], grid[i][j + 1]);
			}
		}
		return grid[0][0];
	}

};