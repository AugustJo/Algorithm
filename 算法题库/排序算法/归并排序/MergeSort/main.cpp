/**
 *  对于一个int数组，请编写一个归并排序算法，对数组元素排序。
 *
 *  给定一个int数组A及数组的大小n，请返回排序后的数组。
 *
 *  测试样例：
 *  [1,2,3,5,2,3],6
 *  [1,2,2,3,3,5]
 *
 */

#include <iostream>

using namespace std;

class MergeSort {
public:
	void Merge(int *a, int n, int *swap, int k) {
		int m = 0, u1, l2, i, j, u2;

		int l1 = 0;                                         //第一个有序子数组下界为0
		while (l1 + k <= n - 1) {
			l2 = l1 + k;                                    //计算第二个有序子数组下届
			u1 = l2 - 1;                                    //计算第一个有序子数组上届
			u2 = (l2 + k - 1 <= n - 1) ? l2 + k - 1 : n - 1;//计算第二个有序子数组上届S

			//两个有序子数组合并
			for (i = l1, j = l2; i <= u1 && j <= u2; ++m) {
				if (a[i] <= a[j]) {
					swap[m] = a[i];
					++i;
				}
				else {
					swap[m] = a[j];
					++j;
				}
			}

			while (i <= u1) {
				swap[m] = a[i];
				++m;
				++i;
			}

			while (j <= u2) {
				swap[m] = a[j];
				++m;
				++j;
			}

			l1 = u2 + 1;
		}

		for (i = l1; i < n; ++i, ++m) swap[m] = a[i];
	}

	int* mergeSort(int* A, int n) {
		if (A == NULL || n <= 1)
			return A;
		int *swap = new int[n];
		int k = 1;
		while (k < n) {
			Merge(A, n, swap, k);
			memcpy(A, swap, n * sizeof(int));
			k = 2 * k;
		}
		delete[]swap;
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

	MergeSort merge_sort;
	merge_sort.mergeSort(A, n);
	for (int i = 0; i < n; ++i) {
		cout << A[i] << ' ';
	}
	cout << endl;

	system("pause");
	delete[]A;
	return 0;
}