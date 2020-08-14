// 一个人上山 每次可以走1步也可以走3步 问到达N台阶一个有多少种走法
// 思路(斐波拉契数列)

#include <iostream>
#include <string>
#include <cstdio>
#include <map>

using namespace std;

// 输入最大行数
#define MAX_LINE 64

int jiecheng(int x)
{
	int result = 1;
	for (int i = x; i > 0; i--)
	{
		result *= i;
	}
	return result;
}

// 计算某个可以方法的次数 3j+k = N[i] 返回（j+k）中选择j或者k的次数
int caculate(int x, int y)
{
	return jiecheng(x + y) / (jiecheng(x)*jiecheng(y));
}

#if defined(__MAIN_DEMO1__)
int main(int argc, char **argv)
{
	int N[MAX_LINE] = { 0 }; // 获取输入
	int M[MAX_LINE] = { 0 }; // 获取输出
	int length = 0;
	string value;
	
	for (;;)
	{
		getline(cin, value);
		if (value.size() == 0)
		{
			break;
		}
		N[length++] = atoi(value.c_str());
	}
	// j代表走三步的次数 k代表走一步的次数    
	int x =0 , y = 0;
	map<int, map<int, int> > finalmap;
	for (int i = 0; i < length; ++i)
	{
		map<int, int> middlemap;
		for (int j = 0; j <= N[i]; ++j)
		{
			for (int k = 0; k <= N[i]; ++k)
			{
				if ((3*j + k) == N[i])
				{
					middlemap.insert(make_pair(j, k));
				}
			}
		}
		finalmap.insert(make_pair(i, middlemap));
	}

	// 计算最后的值
	for (int i = 0; i < length; ++i)
	{
		map<int, int> testmap = finalmap.at(i);
		map<int, int>::iterator iter = testmap.begin();
		int value = 0;
		for (; iter != testmap.end(); ++iter)
		{
			value += caculate(iter->first, iter->second);
		}
		M[i] = value;
	}

	// 输出
	for (int i = 0; i < length; ++i) 
	{
		printf("%d\n", M[i]);
	}
	system("pause");
	return 0;
}
#endif