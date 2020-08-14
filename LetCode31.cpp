#include <vector>
#include <algorithm>

using  std::vector;
using  std::swap;

class Solution {
public:
	void nextPermutation1(vector<int>& nums) {
		next_permutation(nums.begin(), nums.end());
	}


	// ������һ��
	void nextPermutation(vector<int>& nums)
	{
		// �ҵ�һ���ݼ�����
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

		if (i == 0)//��������һ����������
		{
			sort(nums.begin(), nums.end());//�����ų���С����
			return;
		}

		sort(nums.begin() + i, nums.end());
		int j = i;
		for (; j < nums.size(); j++)
			if (nums[j] > nums[flag]) break;//�ҵ��պô���a[flag]����

		//����������
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