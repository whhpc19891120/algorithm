#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix)
	{
		if (!matrix.size()) return 0;
		vector<int> dp(matrix[0].size(), 0);//dp���ڼ�¼��ĳһ��Ϊ�ף���֮ǰ�������ϲ�����γɵ������߶�
		int maxArea = 0;
		/*
		ѭ���е���maxRectangleArea()�㷨��
		�����ҵ���һ���н��matrix[i][j]��������dp[j]�߶ȵ������
		����͵����ҵ��ĳ� * ��
		*/
		for (int i = 0; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[0].size(); ++j)
			{
				dp[j] = (matrix[i][j] == '1') ? dp[j] + 1 : 0;
			}
			maxArea = max(maxArea, maxRectangleArea(dp));
		}
		return maxArea;
	}
private:
	//84.��״ͼ�����ľ��� �Ĵ���
	//�����ҵ�nums������������ǰ�߶ȵ�����
	int maxRectangleArea(vector<int> &nums)
	{
		stack<int> s;//����ջ
		nums.push_back(0);//����һ���ڱ�����nums���������ʱ����õ�����߶ȿ��õ���ջǰ�������Ԫ�س�ջ
		int maxArea = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			while (!s.empty() && nums[i] <= nums[s.top()])
			{
				int top = s.top(); s.pop();
				maxArea = max(maxArea, nums[top] * (s.empty() ? i : i - s.top() - 1));
			}
			s.push(i);
		}
		nums.pop_back();
		return maxArea;
	}
};
