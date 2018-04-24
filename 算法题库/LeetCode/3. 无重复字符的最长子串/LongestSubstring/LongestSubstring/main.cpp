/************************************************************************/
/**
����һ���ַ������ҳ��������ظ��ַ��� ��Ӵ� �ĳ��ȡ�

ʾ����

���� "abcabcbb" ��û���ظ��ַ�����Ӵ��� "abc" ����ô���Ⱦ���3��

���� "bbbbb" ������Ӵ����� "b" ��������1��

���� "pwwkew" ����Ӵ��� "wke" ��������3����ע��𰸱�����һ���Ӵ���"pwke" �� ������ �������Ӵ���
*/
/************************************************************************/
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <map>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ret = 0;
		map<char, int> m;
		int start = 1;

		for(int i = 1; i <= s.length(); ++i){
			char c = s[i - 1];
			if(m[c] >= start){
				start = m[c] + 1;
				m[c] = i;
			}
			else{
				m[c] = i;
				ret = max(ret, i - start + 1);
			}
		}

		return ret;
	}
};

int main(){

	string s;
	class Solution S;
	getline(cin, s);
	//cin >> s;
	int ret = S.lengthOfLongestSubstring(s);
	cout << ret << endl;

	system("pause");
	return 0;
}

