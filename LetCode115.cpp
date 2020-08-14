/*
����һ���ַ���?S?��һ���ַ���?T�������� S ���������� T ���ֵĸ�����

һ���ַ�����һ����������ָ��ͨ��ɾ��һЩ��Ҳ���Բ�ɾ�����ַ��Ҳ�����ʣ���ַ����λ������ɵ����ַ����������磬"ACE"?��?"ABCDE"?��һ�������У���?"AEC"?���ǣ�

ʾ��?1:

����: S = "rabbbit", T = "rabbit"
���:?3
����:

����ͼ��ʾ, �� 3 �ֿ��Դ� S �еõ� "rabbit" �ķ�����
(�ϼ�ͷ���� ^ ��ʾѡȡ����ĸ)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^
ʾ��?2:

����: S = "babgbag", T = "bag"
���:?5
����:

����ͼ��ʾ, �� 5 �ֿ��Դ� S �еõ� "bag" �ķ�����
(�ϼ�ͷ���� ^ ��ʾѡȡ����ĸ)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
	^^^
*/


/*
״̬��ʾ��dp[i][j]��ʾd��ǰi���ַ��������������t��ǰj���ַ��ķ�������
�����ս��Ӧ��Ϊ��dp[s.size()][t.size()]
״̬ת�ƣ�
����dp[i][j]��s[i-1]��t[j-1]�����������

s[i-1] == t[j-1]ʱ�����ʱ������s[i-1]�����ִ�����:
(1)����s[i-1]���������е����һ���ַ�������£��䷽��������s��ǰi-1�ܹ���t��ǰj-1���ķ�����dp[i-1][j-1]
(2)��������s[i-1]ʱ��ʣ���s��ǰi-1���ܹ���t��ǰj���ķ�������dp[i-1][j]���յķ�����Ϊ������ӣ�dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
s[i-1] != t[j-1]ʱ����ʱ�ķ������ȼ����Ƴ�s�ĵ�i��Ԫ�غ�ʣ���ǰi-1��Ԫ�ص��������ܹ���t��ǰj��Ԫ�صķ�������dp[i][j] = dp[i-1][j]
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int numDistinct(string s, string t) 
	{
		int n = s.size(), m = t.size();
		if (m == 0) return 1;
		if (n == 0) return 0;
		vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
		// dp[i][0] = 1, dp[0][j] = 0;
		for (int i = 0; i <= n; i++) dp[i][0] = 1;
		// ״̬ת��
		// s[i-1] == t[j-1]ʱ��dp[i][j] = dp[i-1][j-1] + dp[i-1][j]  dp[i-1][j-1]��ʾ����s[i-1]�������dp[i-1][j]��ʾ�Ƴ�s[i-1]�����
		// s[i-1] != t[j-1]ʱ��dp[i][j] = dp[i-1][j]
		for (int i = 1; i <= n; i++) 
		{
			for (int j = 1; j <= m; j++) 
			{
				dp[i][j] = dp[i - 1][j];
				if (s[i - 1] == t[j - 1]) 
					dp[i][j] += dp[i - 1][j - 1];
			}
		}

		return dp[n][m];
	}
};
