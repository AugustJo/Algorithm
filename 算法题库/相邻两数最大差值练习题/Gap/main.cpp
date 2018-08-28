/**
 * 有一个整形数组A，请设计一个复杂度为O(n)的算法，算出排序后相邻两数的最大差值。
 *
 * 给定一个int数组A和A的大小n，请返回最大的差值。保证数组元素多于1个。
 *
 * 测试样例：
 * [1,2,5,4,6],5
 * 返回：2
 */

#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Gap {
public:
	int maxGap(vector<int> A, int n) {
		// write code here
		if (n < 2)
			return 0;
		set<int> iset;
		for (const auto &i : A)
			iset.insert(i);
		auto pre = iset.begin();
		int max = 0;
		for (auto iter = ++iset.begin(); iter != iset.end(); ++iter)
		{
			if (*iter - *pre > max)
				max = *iter - *pre;
			++pre;
		}
		return max;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> A(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}

	class Gap gap;
	int max = gap.maxGap(A, n);
	cout << max << endl;

	system("pause");
	return 0;
}