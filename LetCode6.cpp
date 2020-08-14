/*
��һ�������ַ������ݸ������������Դ������¡������ҽ���?Z �������С�

���������ַ���Ϊ "LEETCODEISHIRING"?����Ϊ 3 ʱ���������£�

L   C   I   R
E T O E S I I G
E   D   H   N
֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"LCIRETOESIIGEDHN"��

����ʵ��������ַ�������ָ�������任�ĺ�����

string convert(string s, int numRows);
ʾ��?1:

����: s = "LEETCODEISHIRING", numRows = 3
���: "LCIRETOESIIGEDHN"
ʾ��?2:

����: s = "LEETCODEISHIRING", numRows =?4
���:?"LDREOEIIECIHNTSG"
����:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
*/


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	string convert(string s, int numRows) 
	{
		// �ҵ�˼·�����ǵ����еĴ洢��ʵ���Ͽ��Բ������еĴ洢��ֱ��˳��ӵ�ĳһ�к��棨*��
		if (numRows == 1) 
			return s;

		vector<string> rows(min(numRows, int(s.size()))); // ��ֹs�ĳ���С������
		int curRow = 0;
		bool goingDown = false;

		for (char c : s) 
		{
			rows[curRow] += c;
			if (curRow == 0 || curRow == numRows - 1) 
			{// ��ǰ��curRowΪ0��numRows -1ʱ����ͷ��������ת��
				goingDown = !goingDown;
			}
			curRow += goingDown ? 1 : -1;
		}

		string ret;
		for (string row : rows) 
		{// ���ϵ��±�����
			ret += row;
		}

		return ret;
	}
};