/*
����һ���ַ����������ҳ����в������ظ��ַ���?��Ӵ�?�ĳ��ȡ�

ʾ��?1 :

����: "abcabcbb"
	��� : 3
	���� : ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��
	ʾ�� 2 :

	���� : "bbbbb"
	��� : 1
	���� : ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��
	ʾ�� 3 :

	���� : "pwwkew"
	��� : 3
	���� : ��Ϊ���ظ��ַ�����Ӵ���?"wke"�������䳤��Ϊ 3��
	��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke"?��һ�������У������Ӵ�

	��Դ�����ۣ�LeetCode��
	���ӣ�https ://leetcode-cn.com/problems/longest-substring-without-repeating-characters
	����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include <string>

using namespace std;

class Solution 
{
public:
	int lengthOfLongestSubstring(string s) 
	{
		string::size_type pos;
		string str;
		int count = 0;
		int max = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			pos = str.find(s[i]);
			if (pos == str.npos) // û�в鵽
			{
				str.push_back(s[i]);
				count++;
			}
			else
			{
				i -= str.length();
				str.clear();
				count = 0;
			}
			if (count > max)
			{
				max = count;
			}
		}
		return max;
	}
};

#if defined(__LETCODE3__)
void main() 
{
	Solution solution;
	int length = solution.lengthOfLongestSubstring(" ");
	printf("%d\n", length);
	system("pause");
}
#endif