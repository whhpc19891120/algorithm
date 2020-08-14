/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为[2,1,5,6,2,3]。

图中阴影部分为所能勾勒出的最大矩形面积，其面积为10个单位。
示例:

输入: [2,1,5,6,2,3]
输出: 10
*/


/*
遍历高度，求出每个以bar为高度的最大矩形面积，需要向左右遍历，
找出可以向左右扩展的最大宽度，向左右扩展的时间复杂度为O(n)，
为了降低复杂度，通过使用递增单调栈，这样，这样以栈顶元素的bar为高度的左边界就是本身，
而右边界为第一个小于栈顶的元素。
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
		stack<int> s;//单调栈
		heights.push_back(0);//设置一个哨兵，让heights遍历到最后时，获得的柱体高度可让单调栈前面的所有元素出栈
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


