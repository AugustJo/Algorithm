/**
 * 这是一个经典的LIS(即最长上升子序列)问题，请设计一个尽量优的解法求出序列的最长上升子序列的长度。

 * 给定一个序列A及它的长度n(长度小于等于500)，请返回LIS的长度。

 * 测试样例：
 * [1,4,2,5,3],5
 * 返回：3
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class LongestIncreasingSubsequence {
public:
	int getLIS(vector<int> A, int n) {
		// write code here
		if (A.empty() || n < 1)
			return 0;
		int res = 0;
		vector<int> dp(n, 0);
		dp[0] = 1;
		for (int i = 1; i < n; ++i) {
			int curr_max = 0;
			for (int j = i - 1; j >= 0; --j) {
				if (A[i] > A[j] && curr_max < dp[j])
					curr_max = dp[j];
			}
			dp[i] = curr_max + 1;
			res = max(res, dp[i]);
		}
		//sort(dp.begin(), dp.end());
		return res;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> A(n,0);
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	LongestIncreasingSubsequence LIS;
	cout << LIS.getLIS(A, n) << endl;

	system("pause");
	return 0;
}