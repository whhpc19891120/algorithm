/*
��дһ�������������ַ��������е������ǰ׺��

��������ڹ���ǰ׺�����ؿ��ַ��� ""��

ʾ�� 1 :

	���� : ["flower", "flow", "flight"]
	��� : "fl"

ʾ�� 2 :

	���� : ["dog", "racecar", "car"]
	��� : ""
	���� : ���벻���ڹ���ǰ׺��
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) 
	{
		if (strs.size() == 0)
			return "";
		//�����һ���ַ���Ϊ����ǰ׺
		string prefix = strs[0];
		//�ж�ÿһ���ַ������Ƿ���prefix��
		for (int i = 1; i < strs.size(); i++) 
		{
			//���������prefix����prefix���ȼ�1���ٴ��ж�prefix-1�Ƿ�Ϊ���Ӵ���==0��ʾ���и��ִ�����ֱ��prefixΪ�գ�
			while (strs[i].find(prefix)  == strs[i].npos) 
			{
				if (prefix == "") return "";//���prefixΪ�մ�����˵������ǰ׺Ϊ��
				prefix = prefix.substr(0, prefix.length() - 1);
			}
		}
		return prefix;
	}
};