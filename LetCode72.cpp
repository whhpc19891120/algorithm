/*
给定两个单词?word1 和?word2，计算出将?word1?转换成?word2 所使用的最少操作数?。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
示例?1:

输入: word1 = "horse", word2 = "ros"
输出: 3
解释:
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例?2:

输入: word1 = "intention", word2 = "execution"
输出: 5
解释:
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')

*/

//集合表示 dp[i][j] 对前i个字符进行操作,转换为目标的前j个字符的操作次数 属性->操作次数最小值

	//集合划分 dp[i][j]的来源  考虑对第i个字符进行的操作是什么
	//1 插入操作 从而相等 所以先让前i个字符变为j-1字符，然后在第i处插入j代表的字符 即dp[i][j-1]+1
	//2 删除操作 从而相等 所以先让前i-1个字符变为j字符，然后在第i处删除 即dp[i-1][j]+1
	//3 替换操作 从而相等 if(i处等于j处 不需要替换) 即dp[i-1][j-1]
	//                   else 需要替换 dp[i-1][j-1]+1 
	//上述取个最小值即可

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) 
	{
		int n = word1.size(), m = word2.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1));
		for (int i = 0; i <= n; i++) dp[i][0] = i;//i个字符转化为0个字符 只能一直删i次
		for (int j = 0; j <= m; j++) dp[0][j] = j;//0个字符转化为j个字符 只能一直插入j次

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++) 
			{
				dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;//插入 删除 时
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1));//替换时
			}
		}
		return dp[n][m];
	}
};


#if defined(__LETCODE__72__)
void main() 
{
	/*
	c语言中，char* 表示字符指针类型，当其指向一个字符串的第一个元素时，它就可以表示这个字符串。
	如char* str="learn c";中,"learn c"是长度为8的字符数组常量，其最后一个元素是'\0'，
	而这句代表执行的结果是将str指向了"learn c"的第一个字符'l'，str后面的连续内存依次存放'e','a','r','n',' ','c','\0'
	*/
	 
	char * p[] = { (char *)"abc", (char *)"ABC", (char *)"123" };
	printf("%p,%p,%p\n", p, p + 1, p + 2);
	char **pp[] = { p + 2,p + 1, p };
	char ***ppp = pp;
	printf("%s", **++ppp);
	printf("%s", *++*++ppp);
}
#endif
	
