/**
 * ����һ��int���飬���дһ�����������㷨��������Ԫ������

 * ����һ��int����A������Ĵ�Сn���뷵�����������顣

 * ����������
 * [1,2,3,5,2,3],6
 * [1,2,2,3,3,5]
 *
 */
#include <iostream>
using namespace std;

class QuickSort {
public:
	void myQuickSort(int* a, int low, int high) {
		int i = low, j = high;
		int temp = a[low];

		while (i < j) {
			while (i < j && temp <= a[j]) --j;
			if (i < j) {
				a[i] = a[j];
				++i;
			}

			while (i < j && a[i] < temp) ++i;
			if (i < j) {
				a[j] = a[i];
				--j;
			}
		}
		a[i] = temp;

		if (low < i) myQuickSort(a, low, i - 1);
		if (i < high) myQuickSort(a, j + 1, high);
	}

	int* quickSort(int* A, int n) {
		if (A == NULL || n < 2)
			return A;

		myQuickSort(A, 0, n - 1);
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
	QuickSort quick_sort;
	quick_sort.quickSort(A, n);
	for (int i = 0; i < n; ++i) {
		cout << A[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
