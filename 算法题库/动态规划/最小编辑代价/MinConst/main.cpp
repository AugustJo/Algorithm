/**
 * ���������ַ���A��B��������Ҫ���в��롢ɾ�����޸Ĳ�����A����ΪB��������c0��c1��c2�ֱ�Ϊ���ֲ����Ĵ��ۣ������һ����Ч�㷨�������A����ΪB������Ҫ�����ٴ��ۡ�

 * ���������ַ���A��B�������ǵĳ��Ⱥ����ֲ������ۣ��뷵�ؽ�A����ΪB������Ҫ����С���ۡ���֤�������Ⱦ�С�ڵ���300�������ִ���ֵ��С�ڵ���100��

 * ����������
 * "abc",3,"adc",3,5,3,100
 * ���أ�8
 *
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class MinCost {
public:
	int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
		// write code here
		if (A.empty() || B.empty())
			return 0;
		int row = A.length();
		int col = B.length();
		vector<vector<int> > dp(row + 1, vector<int>(col + 1, 0));
		dp[0][0] = 0;
		for (int i = 1; i <= row; ++i) {
			dp[i][0] = i * c1;
		}
		for (int i = 1; i <= col; ++i) {
			dp[0][i] = i * c0;
		}
		for (int i = 1; i <= row; ++i) {
			for (int j = 1; j <= col; ++j) {
				if (A[i - 1] == B[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = dp[i - 1][j - 1] + c2;
				}
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + c0);
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + c1);
			}
		}
		return dp[row][col];
	}
};

