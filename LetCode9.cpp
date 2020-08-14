#include <string>
using namespace std;

// �ж��Ƿ����

class Solution {
public:
	bool isPalindrome1(int x) 
	{
		if (x == 0)
			return true;
		if (x < 0)
			false;
	
		string str = to_string(x);
		string revstr = str;
		std::reverse(revstr.begin(), revstr.end());
		if (str == revstr)
			return true;
		else
			return false;
	}

	bool isPalindrome(int x) 
	{
		// ���������
		// ������������ x < 0 ʱ��x ���ǻ�������
		// ͬ���أ�������ֵ����һλ�� 0��Ϊ��ʹ������Ϊ���ģ�
		// �����һλ����ҲӦ���� 0
		// ֻ�� 0 ������һ����
		if (x < 0 || (x % 10 == 0 && x != 0)) {
			return false;
		}

		// ��Ҫͨ���ַ�����ת Ч�ʵ���
		int revertedNumber = 0;
		while (x > revertedNumber) {
			revertedNumber = revertedNumber * 10 + x % 10;
			x /= 10;
		}

		// �����ֳ���Ϊ����ʱ�����ǿ���ͨ�� revertedNumber/10 ȥ��������λ�����֡�
		// ���磬������Ϊ 12321 ʱ���� while ѭ����ĩβ���ǿ��Եõ� x = 12��revertedNumber = 123��
		// ���ڴ�����λ�����ֲ�Ӱ����ģ����������Լ���ȣ����������ǿ��Լ򵥵ؽ���ȥ����
		return x == revertedNumber || x == revertedNumber / 10;
	}
};

#if defined(__LETCODE9__)
void main()
{
	Solution solution;
	solution.isPalindrome(12321);

}
#endif