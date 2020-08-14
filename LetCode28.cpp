#include <string>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		
		int i  = 0, j = 0;
		while (i < haystack.length() && j < needle.length()) 
		{
			if (haystack[i] != needle[j])
			{
				i = i - j + 1;
				j = 0; // 回0  haystack从第二字符开始比较
			}
			else
			{
				i++;
				j++;
			}
		}
		
		if (j == needle.length()) 
		{
			return i - j;
		}
		
		return -1;
	}
};

#if defined(_LETCODE28_)
void main()
{
	Solution solution;
	int count = solution.strStr("hello", "ll");
	return;
}
#endif