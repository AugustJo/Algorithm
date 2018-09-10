/**
 * 有n级台阶，一个人每次上一级或者两级，问有多少种走完n级台阶的方法。
 * 为了防止溢出，请将结果Mod 1000000007
 * 给定一个正整数int n，请返回一个数，代表上楼的方式数。保证n小于等于100000。
 */
#include <iostream>
#include <vector>

using namespace std;

// 递归暴力搜索
class GoUpstairs_violence_search {
public:
	int countWays(int n) {
		if (n < 1)
			return 0;
		if (n == 1 || n == 2)
			return n;

		return countWays(n - 1) + countWays(n - 2);
	}
};


class GoUpstairs {
public:
	int countWays(int n) {
		// write code here
		if (n < 1)
			return 0;
		if (n == 1 || n == 2)
			return n;
		vector<int> vec(n, 0);
		vec[0] = 1;
		vec[1] = 2;
		for (int i = 2; i < n; ++i) {
			vec[i] = (vec[i - 1] + vec[i - 2]) % 1000000007;
		}
		return vec[n - 1];
	}
};

int main() {
	int n;
	cin >> n;
	GoUpstairs_violence_search GoUpstairs1; // 暴力搜索
	GoUpstairs GoUpstairs2; // 动态规划
	cout << "暴力搜索结果：" << GoUpstairs1.countWays(n) << endl;
	cout << "动态规划结果：" << GoUpstairs2.countWays(n) << endl;

	system("pause");
	return 0;
}