/**
 * 对于一个int数组，请编写一个冒泡排序算法，对数组元素排序。
 *
 * 给定一个int数组A及数组的大小n，请返回排序后的数组。 
 *
 * 测试样例：
 * [1,2,3,5,2,3],6
 * [1,2,2,3,3,5]
 */

#include <iostream>
#include <vector>

using namespace std;

class BubbleSort {
public:
	int* bubbleSort(int* A, int n) {
		if (A == NULL || n <= 1)
			return A;

		int flag = 1;
		int tmp;
		for (int i = n - 1; i > 0 && flag == 1; --i) {
			flag = 0;
			for (int j = 0; j < i; ++j) {
				if (A[j] > A[j + 1]) {
					flag = 1;
					tmp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = tmp;
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

	BubbleSort bubble_sort;
	bubble_sort.bubbleSort(A, n);

	for (int i = 0; i < n; ++i) {
		cout << A[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}