#include <string>
#include <limits>

/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

using namespace std;

class Solution {
public:
	int romanToInt(string s) 
	{
		int sum = 0;
		for (size_t i = 0; i < s.size(); ++i)
		{
			int j = i + 1;
			if (trans(s[i]) >= trans(s[j]))
			{
				sum += trans(s[i]);
			}
			else
			{
				if (s[i] = 'I' && s[j] == 'V')
					sum += 4;
				else if (s[i] = 'I' && s[j] == 'X')
					sum += 9;
				else if (s[i] = 'X' && s[j] == 'L')
					sum += 40;
				else if (s[i] = 'X' && s[j] == 'C')
					sum += 90;
				else if (s[i] = 'C' && s[j] == 'D')
					sum += 400;
				else if (s[i] = 'C' && s[j] == 'M')
					sum += 900;
				++i;
			}
		}
		return sum;
	}

	int trans(char c)
	{
		if (c == 'I')
			return 1;
		else if (c == 'V')
			return 5;
		else if (c == 'X')
			return  10;
		else if (c == 'L')
			return 50;
		else if (c == 'C')
			return 100;
		else if (c == 'D')
			return 500;
		else if (c == 'M')
			return 1000;
		return 0;
	}
};