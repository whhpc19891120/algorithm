/*
������������?word1 ��?word2���������?word1?ת����?word2 ��ʹ�õ����ٲ�����?��

����Զ�һ�����ʽ����������ֲ�����

����һ���ַ�
ɾ��һ���ַ�
�滻һ���ַ�
ʾ��?1:

����: word1 = "horse", word2 = "ros"
���: 3
����:
horse -> rorse (�� 'h' �滻Ϊ 'r')
rorse -> rose (ɾ�� 'r')
rose -> ros (ɾ�� 'e')
ʾ��?2:

����: word1 = "intention", word2 = "execution"
���: 5
����:
intention -> inention (ɾ�� 't')
inention -> enention (�� 'i' �滻Ϊ 'e')
enention -> exention (�� 'n' �滻Ϊ 'x')
exention -> exection (�� 'n' �滻Ϊ 'c')
exection -> execution (���� 'u')

*/

//���ϱ�ʾ dp[i][j] ��ǰi���ַ����в���,ת��ΪĿ���ǰj���ַ��Ĳ������� ����->����������Сֵ

	//���ϻ��� dp[i][j]����Դ  ���ǶԵ�i���ַ����еĲ�����ʲô
	//1 ������� �Ӷ���� ��������ǰi���ַ���Ϊj-1�ַ���Ȼ���ڵ�i������j������ַ� ��dp[i][j-1]+1
	//2 ɾ������ �Ӷ���� ��������ǰi-1���ַ���Ϊj�ַ���Ȼ���ڵ�i��ɾ�� ��dp[i-1][j]+1
	//3 �滻���� �Ӷ���� if(i������j�� ����Ҫ�滻) ��dp[i-1][j-1]
	//                   else ��Ҫ�滻 dp[i-1][j-1]+1 
	//����ȡ����Сֵ����

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
		for (int i = 0; i <= n; i++) dp[i][0] = i;//i���ַ�ת��Ϊ0���ַ� ֻ��һֱɾi��
		for (int j = 0; j <= m; j++) dp[0][j] = j;//0���ַ�ת��Ϊj���ַ� ֻ��һֱ����j��

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++) 
			{
				dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;//���� ɾ�� ʱ
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1));//�滻ʱ
			}
		}
		return dp[n][m];
	}
};


#if defined(__LETCODE__72__)
void main() 
{
	/*
	c�����У�char* ��ʾ�ַ�ָ�����ͣ�����ָ��һ���ַ����ĵ�һ��Ԫ��ʱ�����Ϳ��Ա�ʾ����ַ�����
	��char* str="learn c";��,"learn c"�ǳ���Ϊ8���ַ����鳣���������һ��Ԫ����'\0'��
	��������ִ�еĽ���ǽ�strָ����"learn c"�ĵ�һ���ַ�'l'��str����������ڴ����δ��'e','a','r','n',' ','c','\0'
	*/
	 
	char * p[] = { (char *)"abc", (char *)"ABC", (char *)"123" };
	printf("%p,%p,%p\n", p, p + 1, p + 2);
	char **pp[] = { p + 2,p + 1, p };
	char ***ppp = pp;
	printf("%s", **++ppp);
	printf("%s", *++*++ppp);
}
#endif
	
