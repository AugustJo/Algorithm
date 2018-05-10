/**
 * 请设计一个高效算法，判断数组中是否有重复值。必须保证额外空间复杂度为O(1)。
 *
 * 给定一个int数组A及它的大小n，请返回它是否有重复值。
 *
 * 测试样例：
 * [1, 2, 3, 4, 5, 5, 6], 7
 * 返回：true
 */
#include <iostream>
#include <vector>
using namespace std;

class Checker {
public:
	bool checkDuplicate(vector<int> a, int n) {
		// write code here
		int max = a[0], min = a[0];
		for (int i = 0; i<n; i++) {
			max = (max<a[i]) ? a[i] : max;
			min = (min>a[i]) ? a[i] : min;
		}
		int num = max - min + 1;
		int *b = new int[num];
		memset(b, 0, sizeof(int)*num);
		for (int i = 0; i<n; i++) {
			b[a[i] - min]++;
		}
		for (int i = 0; i<num; i++) {
			if (b[i] >= 2)
				return true;
		}
		return false;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	Checker checker;
	cout << boolalpha << checker.checkDuplicate(A, n) << endl;
	
	system("pause");
	return 0;
}
