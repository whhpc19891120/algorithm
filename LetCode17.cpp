#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

// �绰�������

using namespace std;

class Solution {

private:
	unordered_map<char, string> ump = { {'2', "abc"}, {'3', "def"},
										{'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
										{'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"} };
public:
	void dfs(int index, string & digits, string & str, vector<string> & res) {
		if (index == digits.length()) {
			res.push_back(str);
			return;
		}

		string digtStr = ump[digits[index]];
		for (int i = 0; i < digtStr.length(); i++) {
			str.push_back(digtStr[i]);
			dfs(index + 1, digits, str, res);
			str.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (digits.length() == 0) return res;

		string str;
		dfs(0, digits, str, res);

		return res;
	}

	// ������� ����ʵ��  �������ջʵ��
	vector<string> letterCombinations1(string digits) {
		vector<string> res;//�����������
		unordered_map<char, string> m = { {'2',"abc" },{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };//ӳ��map��ϣ��
		int size = digits.size();//�����ַ���������
		queue<string> que;//�½�����

		//�Ƚ���һ��Ԫ�ض�Ӧ��������
		for (int j = 0; j < m[digits[0]].size(); j++)
		{
			string str;
			str.push_back(m[digits[0]][j]);//charתstring
			que.push(str);//string���
		}
		string s;//���ڴ洢��ͷԪ��
		for (int i = 1; i < size; i++)
		{
			int length = que.size();//��ǰ���г���
			while (length--)
			{
				for (int j = 0; j < m[digits[i]].size(); j++)
				{
					s = que.front();
					s = s + m[digits[i]][j];//��ͷԪ�ؼ�����Ԫ��
					que.push(s);//���
				}
				que.pop();//��ͷ����
			}
		}
		while (!que.empty())
		{
			res.push_back(que.front());//��ͷԪ�ش洢��res
			que.pop();//��ͷ����
		}
		return res;//����
	}
};

#if defined(__LETCODE17__)
void main()
{
	Solution solution;
	vector<string> result = solution.letterCombinations("29");
}
#endif