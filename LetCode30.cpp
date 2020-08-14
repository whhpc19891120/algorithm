#include <vector>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;
using std::vector;

// �滻using namespace

/*
����һ���ַ���?s?��һЩ������ͬ�ĵ���?words���ҳ� s ��ǡ�ÿ�����?words �����е��ʴ����γɵ��Ӵ�����ʼλ�á�

ע���Ӵ�Ҫ��?words �еĵ�����ȫƥ�䣬�м䲻���������ַ���������Ҫ����?words?�е��ʴ�����˳��

?

ʾ�� 1��

���룺
  s = "barfoothefoobarman",
  words = ["foo","bar"]
�����[0,9]
���ͣ�
������ 0 �� 9 ��ʼ���Ӵ��ֱ��� "barfoo" �� "foobar" ��
�����˳����Ҫ, [9,0] Ҳ����Ч�𰸡�
ʾ�� 2��

���룺
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
�����[]

*/

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		//�������ֱ���ų�
		if (s.empty() || words.empty())return {};

		//��Ž��������
		vector<int> result;

		//���������еĵ��ʵĴ�С���������Լ��ܳ���
		int one_word = words[0].size();
		int word_num = words.size();
		int all_len = one_word * word_num;

		//��������->���ʸ�����ӳ��
		unordered_map<string, int> m1;
		for (const auto& w : words)m1[w]++;

		for (int i = 0; i < one_word; ++i)
		{
			//left��rigth��ʾ���ڵ����ұ߽磬count����ͳ��ƥ��ĵ��ʸ���
			int left = i, right = i, count = 0;

			unordered_map<string, int>m2;

			//��ʼ��������
			while (right + one_word <= s.size())
			{
				//��s����ȡһ�����ʿ�����w
				string w = s.substr(right, one_word);
				right += one_word;//�����ұ߽�����һ�����ʵĳ���

				if (m1.count(w) == 0) 
				{
					//�˵��ʲ���words�У���ʾƥ�䲻�ɹ�,Ȼ�����õ��ʸ��������ڱ߽硢�Լ�m2
					count = 0;
					left = right;
					m2.clear();
				}
				else 
				{
					//�õ���ƥ��ɹ�����ӵ�m2��
					m2[w]++;
					count++;
					while (m2.at(w) > m1.at(w))//һ������ƥ���Σ���Ҫ��С���ڣ�Ҳ����left����
					{
						string t_w = s.substr(left, one_word);
						count--;
						m2[t_w]--;
						left += one_word;
					}
					if (count == word_num)result.push_back(left);
				}
			}
		}
		return result;
	}
};

#if defined(__LETCODE_30__)
int main() 
{
	vector<string> vect = { "word","good","best","word" };

	Solution solution;
	solution.findSubstring("wordgoodgoodgoodbestword", vect);
}
#endif