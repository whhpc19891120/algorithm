#include <vector>
#include <algorithm>

using namespace std;

// 三数之和最接近

class Solution
{
public:
	int threeSumClosest(vector<int>& nums, int target) 
	{
		sort(nums.begin(), nums.end());
		int N = nums.size();
		int gap = INT_MAX;
		int sum = 0; // 返回的和
		for (int i = 0; i < N - 2; ++i) {
			int l = i + 1;
			int r = N - 1;
			int temp = 0;
			while (l < r) {
				int s = nums[i] + nums[l] + nums[r];
				temp = abs(s - target);
				if (temp < gap) {
					gap = temp;
					sum = s;
				}

				if (s > target) {
					--r;
				}
				else if (s < target) {
					++l;
				}
				else {
					return s;
				}
			}
		}
		return sum;
	}
};
