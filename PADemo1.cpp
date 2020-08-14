#include <string>
#include <vector>

using namespace std;

string func(vector<string> &strs, char splite)
{
	// 获取总的长度
	int length = 0;
	for (size_t i = 0; i < strs.size(); i++)
	{
		length += strs[i].length();
		if (i != strs.size() - 1) 
		{
			length++;
		}
	}

	char *p = (char *)malloc(length);
	memset(p, 0, length);
	char *q = p;
	for (size_t i = 0; i < strs.size(); i++)
	{
		memcpy(p, strs[i].c_str(), strs[i].size());
		if (i != strs.size() - 1) 
		{
			*p = splite;
			++p;
		}
	}

	string s(q, length);
	free(p);
	return s;
}


string funcext(vector<string> &strs, char splite)
{
	string str;
	for (size_t i = 0; i < strs.size(); i++)
	{
		str += str[i];
		if (i != strs.size() - 1)
		{
			str += splite;
		}
	}
	
	return str;
}


