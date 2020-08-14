#include <iostream>
#include <string>

using namespace std;

int GetMethodCnt(string &str) 
{
	if (str.empty()) 
	{
		return 0;
	}
	if (str.length() > 2) 
	{
		if (atoi(str.substr(0,2).c_str()) <= 26) 
		{
			// 可以分开与合并
			string temp1 = str.substr(1, str.length() - 1);
			string temp2 = str.substr(2, str.length() - 2);

			return GetMethodCnt(temp1) + GetMethodCnt(temp2);
		}
		else 
		{
			// 只能将前两位分开
			string temp = str.substr(1, str.length() - 1);
			return GetMethodCnt(temp);
		}
		
	}
	else if (str.length() == 2) 
	{
		if ((str[0] * 10 + str[1]) > 26) 
		{
			return 2;
		}
		else 
		{
			return 3;
		}
	}
	else if(str.length() == 1)
	{
		return 1;
	}
	return 0;
}
#if defined(__MAIN_DEMO2__)
int main()
{
	// 检测输入是否合法
	bool flag = false;
	std::string str;
	getline(std::cin, str);
	if (str.empty())
	{
		std::cout << "0\n";
		return 0;
	}
	for (int i = 0; i <str.length(); ++i)
	{
		if (str[i] >'0' && str[i] <= '9')
		{
			continue;
		}
		else 
		{
			flag = true;
		}
	}
	if (flag) 
	{
		std::cout << "0\n";
		return 0;
	}
	
	cout << GetMethodCnt(str) << endl;

	system("pause");
	return 0;
}
#endif
