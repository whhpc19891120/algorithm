/*
����һ�������Σ��ҳ��Զ����µ���С·���͡�ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ�

���磬���������Σ�

[
	[2],
	[3, 4],
	[6, 5, 7],
	[4, 1, 8, 3]
]
�Զ����µ���С·����Ϊ ? 11������2 ? +? 3 ? +? 5 ? +? 1 ? = 11����

˵����

��������ֻʹ�� O(n) ? �Ķ���ռ䣨n Ϊ�����ε��������������������⣬��ô����㷨��ܼӷ֡�
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	// ��̬�滮 �Ե�����
	/*
	   ״̬ת�Ʒ��� ��״̬Ϊf(i,i) Ϊ��λ��(i, j)������С·���͡���״̬ת�Ʒ���Ϊ
	   ����ʽ dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
	*/
	int minimumTotal1(vector<vector<int>>& triangle)
	{
		// ��̬�滮, �Ե�����  
		int rowSize = triangle.size();
		vector<vector<int>> dp(triangle);

		// �ӵ����ڶ��п�ʼ
		for (int i = rowSize - 2; i >= 0; i--) 
		{
			// ����ӵ�i�п�ʼ ����i��
			for (int j = 0; j < triangle[i].size(); j++) 
			{
				dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return dp[0][0];
	}

	// ��̬�滮 �Ե�����(ΪminimumTotal1�ռ��ϵ��Ż�)
	/*
	   ״̬ת�Ʒ��� ��״̬Ϊf(i,i) Ϊ��λ��(i, j)������С·���͡���״̬ת�Ʒ���Ϊ
       f(i, j) = min {f(i + 1, j), f(i + 1, j + 1)} + (i, j)
	*/
	int minimumTotal2(vector<vector<int>>& triangle) 
	{
		// �Ե�����
		int n = triangle.size();
		// �����һ������Ϊ��ʼ��״̬
		vector<int> dp(triangle[n - 1]);
		// �ӵ����ڶ��п�ʼ
		for (int i = n - 2; i >= 0; i--)
			// ����ӵ����п�ʼ ��������
			for (int j = 0; j <= i; j++)
				// dp[j] ��ʾ��i�п�ʼ����С·��(dp����ᱻÿ�ж�����)
				dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
		return dp[0];
	}

	// ��̬�滮 �Զ�����
	int minimumTotal3(vector<vector<int>>& triangle)
	{
		// �Զ�����
		int row = triangle.size();  //������
		vector<int> dp(row, INT_MAX);   //����һ��O(n)������,��ֵΪINT_MAX(ͬ���ᱻÿһ�и���)
		dp[0] = triangle[0][0];

		int temp = 0;
		int t = INT_MAX;

		for (int i = 1; i < row; i++)
		{
			temp = INT_MAX;
			for (int j = 0; j <= i; j++)
			{
				t = dp[j];  //������������һ��ʹ��
				dp[j] = min(temp, dp[j]) + triangle[i][j];  //ÿ�θ�triangle[i-1][j-1],triangle[i-1][j]�е���Сֵ���
				temp = t; //temp��ʾ��һ��dp[j]��ֵ��triangle[i-1][j-1] 
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