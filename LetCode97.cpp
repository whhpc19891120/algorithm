/*
���������ַ���?s1, s2, s3, ��֤?s3?�Ƿ�����?s1?��?s2 ������ɵġ�

ʾ�� 1:
����: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
���: true

ʾ�� 2:
����: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
���: false
*/


/*
ά��һ��(m+1)*(n+1)��dp
����һ����ά�������⣬���Կ���s1��ǰi���ַ���s2��ǰj���ַ��Ƿ���Թ���s3��ǰi+j���ַ�
ע����ΪҪά����ʼ�к��У�����±�����漰һЩ����
�����һ��Ϊ1��s1[i-1]����s3[i+j-1]������һ��Ϊ1��s2[j-1]����s3[i+j-1]��dp[i][j]��Ϊ1���������Ϊ0
��ʼ����һ�к͵�һ��ʱע�⣬dp[0][0]=1,��Ϊ�յ�s1�Ϳյ�s2���Թ��ɿյ�s3
*/

/*

*/

#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:

	// ��ά��̬�滮
	bool isInterleave(string s1, string s2, string s3) 
	{
		int N1 = s1.size();
		int N2 = s2.size();
		int N3 = s3.size();
		if (N1 + N2 != N3) return false;
		vector<vector<bool> > dp(N1 + 1, vector<bool>(N2 + 1, false));
		dp[0][0] = true;
		for (int i = 0; i <= N1; ++i) 
		{
			for (int j = 0; j <= N2; ++j) 
			{
				if (i > 0 && s1[i - 1] == s3[i + j - 1]) 
				{
					dp[i][j] = dp[i][j] || dp[i - 1][j];
				}
				if (j > 0 && s2[j - 1] == s3[i + j - 1]) 
				{
					dp[i][j] = dp[i][j] || dp[i][j - 1];
				}
			}
		}
		return dp[N1][N2];
	}

	// һά��̬�滮
	bool isInterleave2(string s1, string s2, string s3) 
	{
		if (s3.length() != s1.length() + s2.length()) {
			return false;
		}
		vector<bool> dp(s2.length() + 1);
		for (int i = 0; i <= s1.length(); i++) 
		{
			for (int j = 0; j <= s2.length(); j++) 
			{
				if (i == 0 && j == 0) 
				{
					dp[j] = true;
				}
				else if (i == 0) 
				{
					dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
				}
				else if (j == 0) 
				{
					dp[j] = dp[j] && s1[i - 1] == s3[i + j - 1];
				}
				else 
				{
					dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1] || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]));
				}
			}
		}
		return dp[s2.length()];
	}

};


#if defined(__LETCODE_97__)
void main() 
{
	Solution solution;
	solution.isInterleave("aabcc", "dbbca", "aadbbcbcac");
}
#endif