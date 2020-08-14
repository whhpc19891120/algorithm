/*
����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�

����㷨ʱ�临�Ӷȱ�����?O(log n) ����

��������в�����Ŀ��ֵ������?[-1, -1]��

ʾ�� 1:

����: nums = [5,7,7,8,8,10], target = 8
���: [3,4]
ʾ��?2:

����: nums = [5,7,7,8,8,10], target = 6
���: [-1,-1]
*/

#include<vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	// �����㷨O(N)
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

	// ���ֲ���
	vector<int> searchRange2(vector<int>& nums, int target) 
	{
		int left = 0, right = nums.size(), mid;
		vector<int> res;
		while (left < right) 
		{    //����߽�
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
		{    //���ұ߽�
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
		//���ص�һ�����ڵ���target�ĵ�����
		vector<int>::iterator left = lower_bound(nums.begin(), nums.end(), target);
		//���ص�һ������target�ĵ�����
		vector<int>::iterator right = upper_bound(nums.begin(), nums.end(), target);
		if (left == right) 
			return { -1,-1 };
		return { int(left - nums.begin()), int(right - nums.begin()) - 1 };
	}
};
