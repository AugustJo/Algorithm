/**
 * һ��������һ���ĳ���cap����N����Ʒ��ÿ�������Լ��ļ�ֵ����¼������v�У�Ҳ�����Լ�����������¼������w�У�ÿ����Ʒֻ��ѡ��Ҫװ�뱳�����ǲ�װ�뱳����Ҫ���ڲ������������ص�ǰ���£�ѡ����Ʒ���ܼ�ֵ���

 * ������Ʒ������w��ֵv����Ʒ��n�ͳ���cap���뷵������ܼ�ֵ��

 * ����������
 * [1,2,3],[1,2,3],3,6
 * ���أ�6
 */
// �ϴ�ͨ���Ĵ���
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



