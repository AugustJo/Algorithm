/**
 * 一个背包有一定的承重cap，有N件物品，每件都有自己的价值，记录在数组v中，也都有自己的重量，记录在数组w中，每件物品只能选择要装入背包还是不装入背包，要求在不超过背包承重的前提下，选出物品的总价值最大。

 * 给定物品的重量w价值v及物品数n和承重cap。请返回最大总价值。

 * 测试样例：
 * [1,2,3],[1,2,3],3,6
 * 返回：6
 */
// 上次通过的代码
//class Backpack {
//public:
//	int maxValue(vector<int> w, vector<int> v, int n, int cap) {
//		// write code here
//		if (w.empty() || v.empty() || n <= 0 || cap <= 0)
//			return 0;
//		vector<vector<int> > dp(n + 1, vector<int>(cap + 1, 0));
//		for (int i = 1; i <= cap; ++i) {
//			if (i >= w[0])
//				dp[1][i] = v[0];
//		}
//
//		for (int i = 2; i <= n; ++i) {
//			for (int j = 1; j <= cap; ++j) {
//				if (j >= w[i - 1])
//					dp[i][j] = max(dp[i - 1][j], (dp[i - 1][j - w[i - 1]] + v[i - 1]));
//				else
//					dp[i][j] = dp[i - 1][j];
//			}
//		}
//
//		return dp[n][cap];
//	}
//};
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Backpack {
public:
	int maxValue(vector<int> w, vector<int> v, int n, int cap) {
		// write code here
		if (w.empty() || v.empty() || w.size() != v.size())
			return 0;
		vector<vector<int> > dp(n + 1, vector<int>(cap + 1, 0));
		for (int i = 1; i <= cap; ++i) {
			if (i >= w[0])
				dp[1][i] = v[0];
		}

		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j <= cap; ++j) {
				if (j >= w[i - 1]) {
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
				}
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		
		return dp[n][cap];
	}
};

int main() {
	int n,cap;
	cin >> n >> cap;
	vector<int> w(n);
	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> w[i];
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	Backpack backpack;
	cout << backpack.maxValue(w, v, n, cap) << endl;
	
	system("pause");
	return 0;
}



