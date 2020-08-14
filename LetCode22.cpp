#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:

	/*
	Ϊ�������������У�����ʹ�õݹ顣����Ϊ n �����о��� '(' �������г���Ϊ n-1 �����У��Լ� ')' �������г���Ϊ n-1 �����С�
    Ϊ�˼�������Ƿ�Ϊ��Ч�ģ����ǻ���� ƽ�⣬Ҳ���������ŵ�������ȥ�����ŵ������ľ�ֵ��
	������ֵʼ��С������߲���������������о�����Ч�ģ�����������Ч�ġ�
	*/

	// ��������(X)
	vector<string> generateParenthesis1(int n) 
	{
		vector<string> combinations;
		string str;
		str.resize(2 * n);
		generateAll(str, 0, combinations);
		return combinations;

	}

	void generateAll(string str, int pos, vector<string> &result) {
		if (pos == str.length()) {
			if (valid(str))
				result.emplace_back(str);
		}
		else 
		{
			str[pos] = '(';
			generateAll(str, pos + 1, result);
			str[pos] = ')';
			generateAll(str, pos + 1, result);
		}
	}

	bool valid(string str) {
		int balance = 0;
		for (char c : str) {
			if (c == '(') balance++;
			else balance--;
			if (balance < 0) return false;
		}
		return (balance == 0);
	}


	/*
	�պϷ����:
�㷨: �ݹ��ϵ n����Ч����������c ����Ч�������к� n-c����Ч�����������
n����Ч�������� ���� "(" + $1 + ")" + $2 ƴ�Ӷ���, $1 ��ʾc(0<=c<n)����Ч�������м����е�ĳһ��Ԫ��, 
$2��ʾʣ�µ�n-1-c����Ч�������й��ɵļ����е�ĳһ��Ԫ��. ����˵���¾��ܿ�����������ʲô��
����Ҫ˵һ��ΪʲôҪans.add("(" + left + ")" + right); ������ans.add(left+right)��,
Ӧ������Ϊ��һ���������� ���left right(n=4) ȫ��()() ���ַָ���С���� 
��(left,right)Ϊ(1,3)����(2,2)����(3,1) �ͻ����()()()()�ظ����ֶ�ε����, 
�����������������Խ�()()()()������ŵ�left=0,rigint=3�������,��ֻ�����һ��, �ǳ�nice
	*/
	// �պ���
	vector<string> generateParenthesis2(int n)
	{
		vector<string> res;
		if (n == 0)  res.emplace_back("");
		for (int i = 0; i < n; i++)
			for (string left : generateParenthesis2(i))
				for (string right : generateParenthesis2(n - 1 - i))
					res.emplace_back("(" + left + ")" + right);
		return res;
	}

	// ����left��right�ֱ��¼�Ѿ���ӵ��������ŵ���Ŀ���򵥻��ݼ���
	void backtrace(int left, int right, int n, string& s, vector<string>& res) {
		if (left == n && right == n) {
			res.push_back(s);
			return;
		}
		if (left < n) {
			s += "(";
			backtrace(left + 1, right, n, s, res);
			s.pop_back();
		}
		if (right < left) {
			s += ")";
			backtrace(left, right + 1, n, s, res);
			s.pop_back();
		}
	}
	vector<string> generateParenthesis3(int n) {
		vector<string> res;
		string s;
		backtrace(0, 0, n, s, res);
		return res;
	}
};

#if defined(_LETCODE22_)
void main()
{
	Solution solution;
	vector<string> result = solution.generateParenthesis1(2);
}
#endif