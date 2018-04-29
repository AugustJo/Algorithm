/**
 对于一个int数组，请编写一个基数排序算法，对数组元素排序。

 给定一个int数组A及数组的大小n，请返回排序后的数组。保证元素均小于等于2000。

 测试样例：
 [1,2,3,5,2,3],6
 [1,2,2,3,3,5]
 */
#include <iostream>
#include <queue>

using namespace std;

class RadixSort {
public:
	int* radixSort(int* A, int n) {
		if (A == NULL || n < 2)
			return A;

		queue<int> barrel[10];
		for (int i = 0; i <= 3; ++i) {
			for (int j = 0; j < n; ++j) {
				int temp = A[j];
				for (int k = 0; k < i; ++k)
					temp /= 10;
				temp %= 10;
				barrel[temp].push(A[j]);
			}

			int index = 0;
			for (int j = 0; j < 10; ++j) {
				while (!barrel[j].empty()) {
					A[index++] = barrel[j].front();
					barrel[j].pop();
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
	RadixSort radix_sort;
	radix_sort.radixSort(A, n);
	for (int i = 0; i < n; ++i) {
		cout << A[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}