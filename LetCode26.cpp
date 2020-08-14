#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		auto itpos = unique(nums.begin(), nums.end());
		nums.erase(itpos, nums.end());
		return itpos - nums.begin();
	}

	int removeDuplicates2(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int i = 0;
		for (int j = 1; j < nums.size(); j++)
		{
			if (nums[j] != nums[i])
			{
				i++;
				nums[i] = nums[j];
			}
		}
		return i + 1;
	}
};


#if defined(__LETCODE26__)
void main()
{
	Solution solution;
	vector<int> vect = { 1,1,2,2,2,3,3 };
	int count = solution.removeDuplicates2(vect);
	return;
}
#endif