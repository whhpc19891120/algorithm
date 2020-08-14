#include <string>
#include <limits>
#include <vector>

/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

���磬 �������� 2 д��?II?����Ϊ�������е� 1��12 д��?XII?����Ϊ?X?+?II?�� 27 д��??XXVII, ��Ϊ?XX?+?V?+?II?��

ͨ������£�����������С�������ڴ�����ֵ��ұߡ���Ҳ�������������� 4 ��д��?IIII������?IV������ 1 ������ 5 ����ߣ�����ʾ�������ڴ��� 5 ��С�� 1 �õ�����ֵ 4 ��ͬ���أ����� 9 ��ʾΪ?IX���������Ĺ���ֻ�������������������

I?���Է���?V?(5) ��?X?(10) ����ߣ�����ʾ 4 �� 9��
X?���Է���?L?(50) ��?C?(100) ����ߣ�����ʾ 40 ��?90��?
C?���Է���?D?(500) ��?M?(1000) ����ߣ�����ʾ?400 ��?900��
����һ������������תΪ�������֡�����ȷ���� 1?�� 3999 �ķ�Χ

*/

using namespace std;

class Solution {
public:
	string intToRoman(int num) 
	{
		string str;
		vector<int> vect;
		int k = 0;
		while (num > 0)
		{
			vect.push_back((num % 10) * pow(10, k++));
			num /= 10;
		}
		std::reverse(vect.begin(), vect.end());
		int count = 0;
		for (size_t i = 0; i < vect.size(); ++i)
		{
			count = 0;
			if (vect[i] >= 1000)
			{
				count = vect[i] / 1000;
				while (count-- > 0)
					str.push_back('M');
			}
			else if (vect[i] == 900)
			{
				str.push_back('C');
				str.push_back('M');
			}
			else if (vect[i] >= 500)
			{
				str.push_back('D');
				int count = (vect[i] - 500) / 100;
				while (count-- > 0)
					str.push_back('C');
			}
			else if (vect[i] == 400)
			{
				str.push_back('C');
				str.push_back('D');
			}
			else if (vect[i] >= 100)
			{
				str.push_back('C');
				int count = (vect[i] - 100) / 100;
				while (count-- > 0)
					str.push_back('C');
			}
			else if (vect[i] == 90)
			{
				str.push_back('X');
				str.push_back('C');
			}
			else if (vect[i] >= 50)
			{
				str.push_back('L');
				count = (vect[i] - 50) / 10;
				while (count-- > 0)
					str.push_back('X');
			}
			else if (vect[i] == 40)
			{
				str.push_back('X');
				str.push_back('L');
			}
			else if (vect[i] >= 10)
			{
				str.push_back('X');
				int count = (vect[i] - 10) / 10;
				while (count-- > 0)
					str.push_back('X');
			}
			else if (vect[i] == 9)
			{
				str.push_back('I');
				str.push_back('X');
			}
			else if (vect[i] >= 5)
			{
				str.push_back('V');
				count = (vect[i] - 5);
				while (count-- > 0)
					str.push_back('I');
			}
			else if (vect[i] == 4)
			{
				str.push_back('I');
				str.push_back('V');
			}
			else if (vect[i] >= 1)
			{
				count = vect[i];
				while (count > 0)
				{
					str.push_back('I');
					count--;
				}
			}
		}
		return str;
	}
};

#if defined(__LETCODE12__)
void main() 
{
	Solution solution;
	string str = solution.intToRoman(1994);
}
#endif