/*
����������СΪ m �� n ����������?nums1 ��?nums2��

�����ҳ������������������λ��������Ҫ���㷨��ʱ�临�Ӷ�Ϊ?O(log(m + n))��

����Լ���?nums1?��?nums2?����ͬʱΪ�ա�

ʾ�� 1:

nums1 = [1, 3]
nums2 = [2]

����λ���� 2.0
ʾ�� 2:

nums1 = [1, 2]
nums2 = [3, 4]

����λ���� (2 + 3)/2 = 2.5

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/median-of-two-sorted-arrays
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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