#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>

// 电话键盘组合

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

	// 广度优先 队列实现  深度优先栈实现
	vector<string> letterCombinations1(string digits) {
		vector<string> res;//用于输出向量
		unordered_map<char, string> m = { {'2',"abc" },{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };//映射map哈希表
		int size = digits.size();//输入字符串产长度
		queue<string> que;//新建队列

		//先将第一个元素对应的码表入队
		for (int j = 0; j < m[digits[0]].size(); j++)
		{
			string str;
			str.push_back(m[digits[0]][j]);//char转string
			que.push(str);//string入队
		}
		string s;//用于存储队头元素
		for (int i = 1; i < size; i++)
		{
			int length = que.size();//当前队列长度
			while (length--)
			{
				for (int j = 0; j < m[digits[i]].size(); j++)
				{
					s = que.front();
					s = s + m[digits[i]][j];//队头元素加上新元素
					que.push(s);//入队
				}
				que.pop();//队头出队
			}
		}
		while (!que.empty())
		{
			res.push_back(que.front());//队头元素存储至res
			que.pop();//队头出队
		}
		return res;//返回
	}
};

#if defined(__LETCODE17__)
void main()
{
	Solution solution;
	vector<string> result = solution.letterCombinations("29");
}
#endif