#include <string>
#include <limits>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		/*
		int d=0;
		istringstream is(str);
		is>>d;
		return d;
		*/

		int res = 0;
		int i = 0;
		int flag = 1;
		// 1. ���ո�
		while (str[i] == ' ') { i++; }
		// 2. ������
		if (str[i] == '-') { flag = -1; }
		if (str[i] == '+' || str[i] == '-') { i++; }
		// 3. ��������
		while (i < str.size() && isdigit(str[i])) {
			int r = str[i] - '0';
			// ------ 4. ������������ǹؼ����� ------
			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7)) {
				return flag > 0 ? INT_MAX : INT_MIN;
			}
			// ------------------------------------
			res = res * 10 + r;
			i++;
		}
		return flag > 0 ? res : -res;
	}
};