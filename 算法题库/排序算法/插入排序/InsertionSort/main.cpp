/**
 *
 * ����һ��int���飬���дһ�����������㷨��������Ԫ������

 * ����һ��int����A������Ĵ�Сn���뷵�����������顣

 * ����������
 * [1,2,3,5,2,3],6
 * [1,2,2,3,3,5]
 */
#include <iostream>

using namespace std;

class InsertionSort {
public:
	int* insertionSort(int* A, int n) {
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
	InsertionSort insert_sort;
	insert_sort.insertionSort(A, n);
	for (int i = 0; i < n; ++i) {
		cout << A[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}