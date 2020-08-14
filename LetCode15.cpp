#include <vector>
#include <algorithm>

using namespace std;

// ÈýÊýºÍ = 0

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		int N = nums.size();
		vector<vector<int> > res;
		for (int i = 0; i < N - 2; ++i) {
			if (nums[i] > 0) break;
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int l = i + 1;
			int r = N - 1;
			while (l < r) {
				int s = nums[i] + nums[l] + nums[r];
				if (s > 0) {
					--r;
				}
				else if (s < 0) {
					++l;
				}
				else {
					res.push_back({ nums[i], nums[l], nums[r] });
					while (l < r && nums[l] == nums[++l]);
					while (l < r && nums[r] == nums[--r]);
				}
			}
		}
		return res;
	}
};


#if defined(__LETCODE15__)
void main() 
{
	vector<int> vect = { -1, 0, 1, 2, -1, -4 };
	Solution solution;
	vector<vector<int>> result =  solution.threeSum(vect);
}
#endif 
