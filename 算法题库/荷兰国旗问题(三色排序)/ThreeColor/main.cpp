/**
 * 有一个只由0，1，2三种元素构成的整数数组，请使用交换、原地排序而不是使用计数进行排序。
 *
 * 给定一个只含0，1，2的整数数组A及它的大小，请返回排序后的数组。保证数组大小小于等于500。
 *
 * 测试样例：
 * [0,1,1,0,2,2],6
 * 返回：[0,0,1,1,2,2]
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ThreeColor {
public:
	vector<int> sortThreeColor(vector<int> A, int n) {
		// write code here
		int low = 0, high = n - 1;
		for (int i = 0; i <= high; i++) {
			if (A[i] == 0) {
				swap(A[i], A[low]);
				low++;
			}
			else if (A[i] == 2) {
				swap(A[i], A[high]);
				high--;
				i--;
			}
		}
		return A;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	ThreeColor sort;
	A = sort.sortThreeColor(A, n);
	for (int i = 0; i < n; ++i) {
		cout << A[i] <<' ';
	}
	cout << endl;

	system("pause");
	return 0;
}