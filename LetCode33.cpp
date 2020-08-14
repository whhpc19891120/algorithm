#include <vector>

using namespace std;


/*
��Ҫ�ھ�����ֲ��ҵĻ��������Ӷ�mid��targetλ����벿�ֻ���λ���Ұ벿�ֵ��ж��߼�
mid��target�ң�left = mid + 1
mid��target��target < nums[mid],right = mid - 1
nums[mid] < target,left = mid + 1

mid�ң�target��right = mid - 1
mid�ң�target�ң�target < nums[mid],right = mid - 1
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
			//midλ���Ұ벿��
			if (nums[mid] < nums[right]) {
				//target <= nums[right],˵��targetλ���Ұ벿��
				//nums[mid] < target,˵��targetλ���Ұ벿�ֵ��Ұ벿��,left = mid + 1
				if (target <= nums[right] && nums[mid] < target) {
					left = mid + 1;
				}
				//target > nums[right],˵��targetλ����벿��,right = mid - 1
				//target < nums[mid],˵��targetλ���Ұ벿�ֵ���벿��,right = mid - 1
				else {
					right = mid - 1;
				}
			}
			//midλ����벿��
			else if (nums[mid] >= nums[right]) {
				//nums[left] <= target,˵��targetλ����벿��
				//target < nums[mid],˵��targetλ����벿�ֵ���벿��,right = mid - 1
				if (nums[left] <= target && target < nums[mid]) {
					right = mid - 1;
				}
				//nums[left] > target,˵��targetλ���Ұ벿��,left = mid + 1
				//target > nums[mid],˵��targetλ����벿�ֵ��Ұ벿��,left = mid + 1
				else {
					left = mid + 1;
				}
			}
		}
		return -1;
	}

	// ̫����
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