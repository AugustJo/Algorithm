/**
 * ��һ������map����ÿ��������һ��Ȩֵ�������Ͻǵĸ��ӿ�ʼÿ��ֻ�����һ��������ߣ�
 *
 * ��󵽴����½ǵ�λ�ã�·�������е������ۼ���������·���ͣ��������е�·������С��·���͡�
 *
 * ����һ������map����������n������m���뷵����С·���͡���֤��������С�ڵ���100.
 *
 * ����������
 * [[1,2,3],[1,1,1]],2,3
 * ���أ�4
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinimunPath {
public:
	int getMin(vector<vector<int> > map, int n, int m) {
		if (map.empty() || map[0].empty() || n < 1 || m < 1)
			return 0;

		vector<vector<int> > dp(n, vector<int>(m, 0));
		dp[0][0] = map[0][0];
		for (int i = 1; i < n; ++i)
			dp[i][0] = dp[i - 1][0] + map[i][0];
		for (int i = 1; i < m; ++i)
			dp[0][i] = dp[0][i - 1] + map[0][i];

		for (int i = 1; i < n; ++i) {
			for (int j = 1; j < m; ++j) {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + map[i][j];
			}
		}

		return dp[n - 1][m - 1];

	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int> > map(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}

	MinimunPath minipath;
	cout << minipath.getMin(map, n, m) << endl;

	system("pause");
	return 0;
}