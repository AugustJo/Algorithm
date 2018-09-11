/**
 * 给定两个字符串A和B，返回两个字符串的最长公共子序列的长度。例如，A="1A2C3D4B56”，B="B1D23CA45B6A”，”123456"或者"12C4B6"都是最长公共子序列。

 * 给定两个字符串A和B，同时给定两个串的长度n和m，请返回最长公共子序列的长度。保证两串长度均小于等于300。

 * 测试样例：
 * "1A2C3D4B56",10,"B1D23CA45B6A",12
 * 返回：6
 */

/*
// 之前通过的代码
class LCS {
public:
int findLCS(string A, int n, string B, int m) {
// write code here
if(A.empty() || n <= 0 || B.empty() || m <= 0)
return 0;
vector<vector<int> > dp(n, vector<int>(m,0));
if(A[0]==B[0]) dp[0][0] = 1;
for(int i = 1; i < n; ++i){
if(A[i] == B[0] || dp[i-1][0] == 1)
dp[i][0] = 1;
}
for(int i = 1; i < m; ++i){
if(A[0] == B[i] || dp[0][i-1] == 1)
dp[0][i] = 1;
}

for(int i=1; i < n; ++i){
for(int j=1; j < m; ++j){
dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
if(A[i] == B[j])
dp[i][j] = max((dp[i-1][j-1] + 1), dp[i][j]);
}
}

return dp[n-1][m-1];
}
};
*/ 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class LCS {
public:
	int findLCS(string A, int n, string B, int m) {
		// write code here
		if (A.empty() || B.empty())
			return 0;

		vector<vector<int> > dp(n, vector<int>(m, 0));
		if (A[0] == B[0]) dp[0][0] = 1;

		for (int i = 1; i < n; ++i)
			if (A[i] == B[0] || dp[i - 1][0] == 1)
				dp[i][0] = 1;
		for (int i = 1; i < m; ++i)
			if (A[0] == B[i] || dp[0][i] == 1)
				dp[0][i] = 1;

		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (A[i] == B[j])
					dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
			}
		}
		return dp[n - 1][m - 1];
	}
};

int main() {
	string A,B;
	cin >> A >> B;
	int n, m;
	n = A.length();
	m = B.length();
	LCS lcs;
	cout << lcs.findLCS(A, n, B, m) << endl;

	system("pause");
	return 0;
}