#include <vector>
using namespace std;

/*
给你一个?n?行?m?列的矩阵，最开始的时候，每个单元格中的值都是 0。

另有一个索引数组?indices，indices[i] = [ri, ci]?中的?ri 和 ci 分别表示指定的行和列（从 0 开始编号）。

你需要将每对?[ri, ci]?指定的行和列上的所有单元格的值加 1。

请你在执行完所有?indices?指定的增量操作后，返回矩阵中 「奇数值单元格」 的数目。

?

示例 1：



输入：n = 2, m = 3, indices = [[0,1],[1,1]]
输出：6
解释：最开始的矩阵是 [[0,0,0],[0,0,0]]。
第一次增量操作后得到 [[1,2,1],[0,1,0]]。
最后的矩阵是 [[1,3,1],[1,3,1]]，里面有 6 个奇数。
示例 2：



输入：n = 2, m = 2, indices = [[1,1],[0,0]]
输出：0
解释：最后的矩阵是 [[2,2],[2,2]]，里面没有奇数。
*/

class Solution {
public:
	int oddCells(int n, int m, vector<vector<int>>& indices) {
		const int M = 50;
		const int N = 50;

		if (n> 50 || n < 1)
		{
			return -1;
		}
		if (n > 50 || n < 1)
		{
			return -2;
		}
		int data[N][M];
		for (size_t i= 0; i < n; ++i)
		{
			for (int j = 0; j< m; ++j)
			{
				data[i][j] = 0;
			}
		}

		int length = indices.size();
		int nn = 0; // 行数 
		int mm = 0; // 列数
		for (size_t i = 0; i < length; ++i)
		{
			nn = indices[i].at(0);
			mm = indices[i].at(1);
			// 增加行
			for (size_t k = 0; k < m; ++k)
			{
				data[nn][k] += 1;
			}
			for (size_t k = 0; k< n; ++k)
			{
				data[k][mm] + 1;
			}
		}

		int size = 0;
		for (size_t i= 0; i< n; ++i)
		{
			for (size_t j = 0; j < m; j++)
			{
				if (data[i][j] / 2 == 1)
					size++;
			}
		}
		return size;
	}
};