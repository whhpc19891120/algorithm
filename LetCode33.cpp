#include <vector>

using namespace std;


/*
需要在经典二分查找的基础上增加对mid和target位于左半部分还是位于右半部分的判断逻辑
mid左，target右，left = mid + 1
mid左，target左，target < nums[mid],right = mid - 1
nums[mid] < target,left = mid + 1

mid右，target左，right = mid - 1
mid右，target右，target < nums[mid],right = mid - 1
nums[mid] < target,left = mid + 1

*/

class Solution {
public:
	int search(vector<int>& nums, int target) 
	{
		if (nums.empty()) return -1;
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			int mid = left + ((right - left) >> 1);
			if (nums[mid] == target) {
				return mid;
			}
			//mid位于右半部分
			if (nums[mid] < nums[right]) {
				//target <= nums[right],说明target位于右半部分
				//nums[mid] < target,说明target位于右半部分的右半部分,left = mid + 1
				if (target <= nums[right] && nums[mid] < target) {
					left = mid + 1;
				}
				//target > nums[right],说明target位于左半部分,right = mid - 1
				//target < nums[mid],说明target位于右半部分的左半部分,right = mid - 1
				else {
					right = mid - 1;
				}
			}
			//mid位于左半部分
			else if (nums[mid] >= nums[right]) {
				//nums[left] <= target,说明target位于左半部分
				//target < nums[mid],说明target位于左半部分的左半部分,right = mid - 1
				if (nums[left] <= target && target < nums[mid]) {
					right = mid - 1;
				}
				//nums[left] > target,说明target位于右半部分,left = mid + 1
				//target > nums[mid],说明target位于左半部分的右半部分,left = mid + 1
				else {
					left = mid + 1;
				}
			}
		}
		return -1;
	}

	// 太难了
	int search2(vector<int>& nums, int target) 
	{
		int lo = 0, hi = nums.size() - 1;
		while (lo < hi) 
		{
			int mid = (lo + hi) / 2;
			if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
				lo = mid + 1;
			else
				hi = mid;
		}
		return lo == hi && nums[lo] == target ? lo : -1;
	}
};

#if defined(__LETCODE_33__)
void main() 
{
	vector<int> nums = { 4,5,6,7,0,1,2 };
	Solution s;
	s.search(nums, 0);
}
#endif