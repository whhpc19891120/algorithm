#include <vector>
#include <algorithm>

using  std::vector;
using  std::swap;

class Solution {
public:
	void nextPermutation1(vector<int>& nums) {
		next_permutation(nums.begin(), nums.end());
	}


	// 更清晰一点
	void nextPermutation(vector<int>& nums)
	{
		// 找第一个递减的数
		int flag = 0;
		int i = nums.size() - 1;
		for (; i > 0; i--)
		{
			if (nums[i - 1] < nums[i])
			{
				flag = i - 1;
				break;
			}
		}

		if (i == 0)//不存在下一个更大排列
		{
			sort(nums.begin(), nums.end());//重新排成最小排列
			return;
		}

		sort(nums.begin() + i, nums.end());
		int j = i;
		for (; j < nums.size(); j++)
			if (nums[j] > nums[flag]) break;//找到刚好大于a[flag]的数

		//交换两个数
		swap(nums[flag], nums[j]);
	}
};


#if defined(__LETCODE30__)
int main() 
{
	vector<int> vect = {1, 4, 3, 2 };

	Solution solution;
	solution.nextPermutation(vect);
}
#endif