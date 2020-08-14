/*
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� ? s ����󳤶�Ϊ 1000��

ʾ�� 1��

���� : "babad"
	��� : "bab"
	ע�� : "aba" Ҳ��һ����Ч�𰸡�
	ʾ�� 2��

	���� : "cbbd"
	��� : "bb"

	��Դ�����ۣ�LeetCode��
	���ӣ�https ://leetcode-cn.com/problems/longest-palindromic-substring
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	// �����ƽⷨ(Ч��̫��)
	string longestPalindrome1(string s) 
	{
		string res = "";//��Ž��
		string temp = "";//����Ӵ�
		for (int i = 0; i < s.length(); i++)
		{
			for (int j = i; j < s.length(); j++)
			{
				temp = temp + s[j];
				string tem = temp;//tem����Ӵ���ת���
				std::reverse(tem.begin(), tem.end());//��ת
				if (temp == tem)
					res = res.length() > temp.length() ? res : temp;
			}
			temp = "";
		}
		return res;
	}

	// ��ת����󹫹��Ӵ� ���ж��Ƿ����(�Ծɻᳬ��ʱ������)
	string longestPalindrome2(string s) 
	{	
		//��СΪ1���ַ�����Ϊ���Ĵ�
		if (s.length() == 1) 
			return s;
		//rev���s��ת���
		string rev = s;
		//��Ž��
		string res;
		std::reverse(rev.begin(), rev.end());
		if (rev == s) 
			return s;
		//��Ż����Ӵ��ĳ���
		int len = 0;
		//����s��rev��������Ӵ�
		for (int i = 0; i < s.length(); i++)
		{
			string temp;//��Ŵ���֤�Ӵ�
			for (int j = i; j < s.length(); j++)
			{
				temp = temp + s[j];
				if (rev.find(temp) != -1)
				{
					//q������֤temp�Ƿ��ǻ����Ӵ�
					string q = temp;
					std::reverse(q.begin(), q.end());
					if (q == temp)
					{
						len = temp.length();
						res = temp;
					}
				}
				else break;
			}
			temp = "";
		}
		return res;
	}

	// ��̬�滮����Ӧʱ��̫�� Do not AC��
	string longestPalindrome3(string s)
	{
		int length = s.size();
		if (length == 0 || length == 1)
			return s;

		//�����ά��̬����
		vector<vector<int>>  dp(length, vector<int>(length));
		int maxLen = 0;
		string maxPal = "";
		for (int len = 1; len <= len; len++) 
		{
			//�������еĳ���
			for (int start = 0; start < length; start++)
			{
				int end = start + len - 1;
				if (end >= length) //�±��Ѿ�Խ�磬��������ѭ��
					break;
				dp[start][end] = (len == 1 || len == 2 || dp[start + 1][end - 1]) && s[start] == s[end]; //����Ϊ 1 �� 2 �ĵ����ж���
				if (dp[start][end] && len > maxLen) 
				{
					maxPal = s.substr(start, end + 1);
				}
			}
		}
		return maxPal;
	}

	// ��̬�滮��AC Ч�ʵ��£�
	string longestPalindrome4(string s) 
	{
		int len = s.size();
		if (len == 0 || len == 1)
			return s;
		int start = 0;//���Ĵ���ʼλ��
		int max = 1;//���Ĵ���󳤶�
		vector<vector<int>>  dp(len, vector<int>(len));//�����ά��̬����
		for (int i = 0; i < len; i++)//��ʼ��״̬
		{
			dp[i][i] = 1;
			if (i < len - 1 && s[i] == s[i + 1])
			{
				dp[i][i + 1] = 1;
				max = 2;
				start = i;
			}
		}
		for (int l = 3; l <= len; l++)//l��ʾ�������Ӵ����ȣ�����3��ʾ�ȼ�������Ϊ3���Ӵ�
		{
			for (int i = 0; i + l - 1 < len; i++)
			{
				int j = l + i - 1;//��ֹ�ַ�λ��
				if (s[i] == s[j] && dp[i + 1][j - 1] == 1)//״̬ת��
				{
					dp[i][j] = 1;
					start = i;
					max = l;
				}
			}
		}
		return s.substr(start, max);//��ȡ������Ӵ�
	}

	// ������ɢ��
	string longestPalindrome(string s) 
	{
		int len = s.size();
		if (len == 0 || len == 1)
			return s;
		int start = 0;//��¼�����Ӵ���ʼλ��
		int end = 0;//��¼�����Ӵ���ֹλ��
		int mlen = 0;//��¼�������Ӵ��ĳ���
		for (int i = 0; i < len; i++)
		{
			int len1 = expendaroundcenter(s, i, i);//һ��Ԫ��Ϊ����
			int len2 = expendaroundcenter(s, i, i + 1);//����Ԫ��Ϊ����
			mlen = max(max(len1, len2), mlen);
			if (mlen > end - start + 1)
			{
				start = i - (mlen - 1) / 2;
				end = i + mlen / 2;
			}
		}
		return s.substr(start, mlen);
		//�ú�������˼�ǻ�ȡ��start��ʼ����Ϊmlen���ȵ��ַ���
	}
private:

	//������left��rightΪ���ĵĻ��Ĵ�����
	int expendaroundcenter(string s, int left, int right)
	{
		int L = left;
		int R = right;
		while (L >= 0 && R < s.length() && s[R] == s[L])
		{
			L--;
			R++;
		}
		return R - L - 1;
	}	
};