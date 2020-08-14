/*
���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 ��

���ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������

��������״ͼ��ʾ��������ÿ�����ӵĿ��Ϊ 1�������ĸ߶�Ϊ[2,1,5,6,2,3]��

ͼ����Ӱ����Ϊ���ܹ��ճ�������������������Ϊ10����λ��
ʾ��:

����: [2,1,5,6,2,3]
���: 10
*/


/*
�����߶ȣ����ÿ����barΪ�߶ȵ��������������Ҫ�����ұ�����
�ҳ�������������չ������ȣ���������չ��ʱ�临�Ӷ�ΪO(n)��
Ϊ�˽��͸��Ӷȣ�ͨ��ʹ�õ�������ջ��������������ջ��Ԫ�ص�barΪ�߶ȵ���߽���Ǳ���
���ұ߽�Ϊ��һ��С��ջ����Ԫ�ء�
/.,mvcxz
 https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/zhu-zhuang-tu-zhong-zui-da-de-ju-xing-by-leetcode/
*/


#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int largestRectangleArea(vector<int>& heights) 
	{
		stack<int> s;//����ջ
		heights.push_back(0);//����һ���ڱ�����heights���������ʱ����õ�����߶ȿ��õ���ջǰ�������Ԫ�س�ջ
		int maxArea = 0;
		for (int i = 0; i < heights.size(); ++i)
		{
			while (!s.empty() && heights[i] <= heights[s.top()])
			{
				int top = s.top(); 
				s.pop();
				maxArea = max(maxArea, heights[top] * (s.empty() ? i : i - s.top() - 1));
			}
			s.push(i);
		}
		heights.pop_back();
		return maxArea;
	}
};

#if defined(__LETCODE_84__)
void main() 
{
	vector<int> heights = { 2,1,5,6,2,3 };

	Solution solution;
	solution.largestRectangleArea(heights);
}
#endif


