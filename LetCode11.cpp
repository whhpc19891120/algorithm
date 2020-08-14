#include <vector>
#include <algorithm>

using namespace std;

// 计算面积

class Solution 
{
public:
	// 暴力破解法
	int maxArea1(vector<int>& height) 
	{
		int max = INT_MIN;
		int area = 0;
		for (size_t i = 1; i< height.size(); ++i)
		{
			area = 0;
			for (size_t j = i + 1; j <= height.size(); ++j)
			{
				area = (j - i)*min(height[j - 1], height[i - 1]);
				if (area > max)
					max = area;
			}
		}
		return max;
	}

	// 双指针法
	int maxArea(vector<int> &height)
	{
		int result = 0;
		int heightSize = int(height.size());
		int leftIndex = 0;
		int rightIndex = heightSize - 1;

		while (leftIndex != rightIndex)
		{
			int tmpHeight;
			int tmpWidth = rightIndex - leftIndex;
			//短的一侧向中间移动
			if (height[leftIndex] < height[rightIndex])
			{
				tmpHeight = height[leftIndex];
				leftIndex++;
			}
			else
			{
				tmpHeight = height[rightIndex];
				rightIndex--;
			}
			int tmpResult = tmpWidth * tmpHeight;
			if (tmpResult > result)
			{
				result = tmpResult;
			}
		}
		return result;
	}
};