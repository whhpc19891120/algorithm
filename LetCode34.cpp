/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是?O(log n) 级别。

如果数组中不存在目标值，返回?[-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例?2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/

#include<vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	// 暴力算法O(N)
	vector<int> searchRange(vector<int>& nums, int target) 
	{
		int start = -1, end = -1;
		vector<int> res;
		for (int i = 0; i < nums.size(); i++) 
		{
			if (start == -1 && nums[i] == target) 
				start = i;
			if (nums[i] == target) 
				end = i;
		}
		res.emplace_back(start);
		res.emplace_back(end);
		return res;
	}

	// 二分查找
	vector<int> searchRange2(vector<int>& nums, int target) 
	{
		int left = 0, right = nums.size(), mid;
		vector<int> res;
		while (left < right) 
		{    //找左边界
			mid = left + (right - left) / 2;
			if (nums[mid] == target) right = mid;
			else if (nums[mid] < target) left = mid + 1;
			else right = mid;
		}
		if (left == nums.size() || nums[left] != target)
			return res = { -1,-1 };
		if (nums[left] == target) 
			res.emplace_back(left);

		right = nums.size();
		while (left < right)
		{    //找右边界
			mid = left + (right - left) / 2;
			if (nums[mid] == target) left = mid + 1;
			else if (nums[mid] < target) left = mid + 1;
			else right = mid;
		}
		if (nums[right - 1] == target) 
			res.emplace_back(right - 1);
		return res;
	}

	// stl
	vector<int> searchRange3(vector<int>& nums, int target) 
	{
		//返回第一个大于等于target的迭代器
		vector<int>::iterator left = lower_bound(nums.begin(), nums.end(), target);
		//返回第一个大于target的迭代器
		vector<int>::iterator right = upper_bound(nums.begin(), nums.end(), target);
		if (left == right) 
			return { -1,-1 };
		return { int(left - nums.begin()), int(right - nums.begin()) - 1 };
	}
};
