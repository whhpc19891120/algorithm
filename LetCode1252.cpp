#include <vector>
using namespace std;

/*
����һ��?n?��?m?�еľ����ʼ��ʱ��ÿ����Ԫ���е�ֵ���� 0��

����һ����������?indices��indices[i] = [ri, ci]?�е�?ri �� ci �ֱ��ʾָ�����к��У��� 0 ��ʼ��ţ���

����Ҫ��ÿ��?[ri, ci]?ָ�����к����ϵ����е�Ԫ���ֵ�� 1��

������ִ��������?indices?ָ�������������󣬷��ؾ����� ������ֵ��Ԫ�� ����Ŀ��

?

ʾ�� 1��



���룺n = 2, m = 3, indices = [[0,1],[1,1]]
�����6
���ͣ��ʼ�ľ����� [[0,0,0],[0,0,0]]��
��һ������������õ� [[1,2,1],[0,1,0]]��
���ľ����� [[1,3,1],[1,3,1]]�������� 6 ��������
ʾ�� 2��



���룺n = 2, m = 2, indices = [[1,1],[0,0]]
�����0
���ͣ����ľ����� [[2,2],[2,2]]������û��������
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
		int nn = 0; // ���� 
		int mm = 0; // ����
		for (size_t i = 0; i < length; ++i)
		{
			nn = indices[i].at(0);
			mm = indices[i].at(1);
			// ������
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