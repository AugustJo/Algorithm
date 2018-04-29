/**
 *  对于一个int数组，请编写一个希尔排序算法，对数组元素排序。
 *
 *  给定一个int数组A及数组的大小n，请返回排序后的数组。保证元素小于等于2000。
 *
 *  测试样例：
 *  [1,2,3,5,2,3],6
 *  [1,2,2,3,3,5]
 *
 */
#include <iostream>
using namespace std;

class ShellSort {
public:
	int* shellSort(int* A, int n) {
		if (A == NULL || n < 2)
			return A;
		int i, j, k, span;
		int temp;
		for (span = n / 2; span > 0; span = span / 2) {     //希尔排序步长从数组总长度开始递减
			for (k = 0; k < span; ++k) {
				for (i = k; i < n - span; i = i + span) {
					temp = A[i + span];
					j = i;
					while (j > -1 && temp < A[j]) {
						A[j + span] = A[j];
						j = j - span;
					}
					A[j + span] = temp;
				}
			}
		}

		return A;
	}
};

int main() {
	int n;
	cin >> n;
	int *A = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	ShellSort shell_sort;
	shell_sort.shellSort(A, n);
	for (int i = 0; i < n; ++i) {
		cout << A[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}