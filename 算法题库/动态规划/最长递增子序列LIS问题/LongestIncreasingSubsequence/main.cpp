/**
 * ����һ�������LIS(�������������)���⣬�����һ�������ŵĽⷨ������е�����������еĳ��ȡ�

 * ����һ������A�����ĳ���n(����С�ڵ���500)���뷵��LIS�ĳ��ȡ�

 * ����������
 * [1,4,2,5,3],5
 * ���أ�3
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