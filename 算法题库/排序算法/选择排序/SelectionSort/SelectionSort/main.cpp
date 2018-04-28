/**
* 对于一个int数组，请编写一个选择排序算法，对数组元素排序。
*
* 给定一个int数组A及数组的大小n，请返回排序后的数组。
*
* 测试样例：
* [1,2,3,5,2,3],6
* [1,2,2,3,3,5]
 */

#include <iostream>

using namespace std;

class SelectionSort {
public:
	int* selectionSort(int* A, int n) {
		if (A == NULL || n <= 1)
			return A;

		int tmp;
		for (int i = 0; i < n - 1; ++i) {
			tmp = A[i + 1];
			int j = i;
			while (j > -1 && tmp < A[j]) {
				A[j + 1] = A[j];
				--j;
			}
			A[j + 1] = tmp;
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

	SelectionSort selection_sort;
	selection_sort.selectionSort(A, n);
	for (int i = 0; i < n; ++i) {
		cout << A[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}