/**
 * ���������ַ���A��B�����������ַ���������������еĳ��ȡ����磬A="1A2C3D4B56����B="B1D23CA45B6A������123456"����"12C4B6"��������������С�

 * ���������ַ���A��B��ͬʱ�����������ĳ���n��m���뷵������������еĳ��ȡ���֤�������Ⱦ�С�ڵ���300��

 * ����������
 * "1A2C3D4B56",10,"B1D23CA45B6A",12
 * ���أ�6
 */

/*
// ֮ǰͨ���Ĵ���
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