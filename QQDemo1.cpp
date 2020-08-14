#include <string>
#include <map>
#include <vector>

using namespace std;

// 字符串分割
void GetSplite(const string &str, char c, vector<string> &vect) 
{
	size_t  pos = str.find(c);
	size_t p = 0; // 指向下一搜索位置
	while (pos != str.npos)
	{
		vect.push_back(str.substr(p, pos -p));
		p = pos + 1; 
		pos = str.find(c, p);
	}
	if (p != str.length())
		vect.push_back(str.substr(p));
}

void main1() 
{
	map<string, string> result;

	vector<string>  vect;
	vector<string> temp;
	string str = "a=b&c=d&e=f";
	GetSplite(str, '&', vect);
	for (auto s : vect)
	{
		temp.clear();
		GetSplite(s, '=', temp);
		if (temp.size() > 1)
			result.insert(make_pair(temp[0], temp[1]));
	}
	
}