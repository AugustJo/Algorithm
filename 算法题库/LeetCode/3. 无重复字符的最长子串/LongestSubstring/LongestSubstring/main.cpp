/************************************************************************/
/**
给定一个字符串，找出不含有重复字符的 最长子串 的长度。

示例：

给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。

给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。

给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列 而不是子串。
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

