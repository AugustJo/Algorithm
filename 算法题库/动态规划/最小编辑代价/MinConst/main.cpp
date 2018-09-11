/**
 * 对于两个字符串A和B，我们需要进行插入、删除和修改操作将A串变为B串，定义c0，c1，c2分别为三种操作的代价，请设计一个高效算法，求出将A串变为B串所需要的最少代价。

 * 给定两个字符串A和B，及它们的长度和三种操作代价，请返回将A串变为B串所需要的最小代价。保证两串长度均小于等于300，且三种代价值均小于等于100。

 * 测试样例：
 * "abc",3,"adc",3,5,3,100
 * 返回：8
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

