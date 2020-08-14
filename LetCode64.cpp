
/*
����һ�������Ǹ������� m?x?n?�������ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��

˵����ÿ��ֻ�����»��������ƶ�һ����

ʾ��:

����:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
���: 7
����: ��Ϊ·�� 1��3��1��1��1 ���ܺ���С��
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	/*
	�����½�һ������� dpdp ���飬��ԭ�����С��ͬ������������У�dp(i, j)dp(i,j) ��ʾ������ (i, j)(i,j) �����½ǵ���С·��Ȩֵ��
	���ǳ�ʼ�����½ǵ� dpdp ֵΪ��Ӧ��ԭ����ֵ��Ȼ��ȥ���������󣬶���ÿ��Ԫ�ؿ����ƶ����ұ߻������棬��˻����С·�������������µ��ƹ�ʽ��
	dp(i,j)=grid(i,j)+min(dp(i+1,j),dp(i,j+1))

	*/
	// ��ά��̬�滮(��������)
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
	���ϸ��ⷨ�У����ǿ�����һ��һά�����������ά���飬dpdp ����Ĵ�С���д�С��ͬ��
������Ϊ����ĳ���̶�״̬��ֻ��Ҫ�����·����Ҳ�Ľڵ㡣
���ȳ�ʼ�� dpdp �������һ��Ԫ�������½ǵ�Ԫ��ֵ��Ȼ�����������Ƹ���ÿ�� dp(j)dp(j) Ϊ��

dp(j)=grid(i,j)+min(dp(j),dp(j+1))

���Ƕ���ÿһ�ж��ظ�������̣�Ȼ������һ���ƶ���������ɺ� dp(0) �������Ľ����
	*/
	// һά��̬�滮
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
	�ͷ��� 2 ��ͬ��Ωһ�������ǣ�����Ҫ�ö���� dpdp ���飬������ԭ�����ϴ洢�������Ͳ���Ҫ����Ĵ洢�ռ䡣���ƹ�ʽ���£�
	grid(i,j)=grid(i,j)+min(grid(i+1,j),grid(i,j+1))
	*/

	// ��̬�滮(ԭ���޸�)
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