/*
����һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��

ʾ��?1:

����: 123
���: 321
?ʾ�� 2:

����: -123
���: -321
ʾ�� 3:

����: 120
���: 21
ע��:

�������ǵĻ���ֻ�ܴ洢���� 32 λ���з���������������ֵ��ΧΪ?[?231,? 231?? 1]�������������裬�����ת�����������ô�ͷ��� 0��

*/

#include <string>

using namespace std;

class Solution {
public:
	int reverse(int x) 
	{
		int y = x > 0 ? x : x * -1;
		if (x == 0)
			return 0;

		// ȥ��ĩβ0
		while (y%10 == 0) 
		{
			y = y / 10;
		}
		string str = to_string(y);
		std::reverse(str.begin(), str.end());
		string strlimit = to_string((int)pow(2, 32) - 1);
		if (str.length() == strlimit.length() && str > strlimit )
		{
			return 0;
		}
		int k = atoi(str.c_str());
		if (x < 0) 
		{
			k = k * -1;
		}
		return k;
	}
};

#if defined(__LETCODE7__)
void main() 
{
	Solution solution;
	solution.reverse(8);
}
#endif