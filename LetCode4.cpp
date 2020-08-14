/*
给定两个大小为 m 和 n 的有序数组?nums1 和?nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为?O(log(m + n))。

你可以假设?nums1?和?nums2?不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		vector<int> vect;
		int i = 0; 
		int j = 0;
		while (i< nums1.size() && j < nums2.size())
		{
			if (nums1[i] < nums2[j]) 
			{
				vect.push_back(nums1[i]);
				i++;
			}
			else if (nums1[i] > nums2[j])
			{
				vect.push_back(nums2[j]);
				j++;
			}
			else 
			{
				vect.push_back(nums1[i]);
				vect.push_back(nums2[j]);
				i++;
				j++;
			}
		}
		while (i < nums1.size())
		{
			vect.push_back(nums1[i]);
			i++;
		}
		while (j < nums2.size())
		{
			vect.push_back(nums2[j]);
			j++;
		}

		if (vect.size() % 2 == 1) 
		{
			return vect[(vect.size() - 1) / 2];
		}
		else 
		{
			return (double)(vect[vect.size() / 2] + vect[vect.size() / 2 - 1]) / 2;
		}
	}
};

#if defined(__LETCODE3__)
void main()
{
	Solution solution;
	vector<int> v1 = { 1,2 };
	vector<int> v2 = { 3, 4 };
	double value = solution.findMedianSortedArrays(v1, v2);
	printf("%.2f\n", value);
	system("pause");
}
#endif