/**
 *  ����һ��int���飬���дһ���鲢�����㷨��������Ԫ������
 *
 *  ����һ��int����A������Ĵ�Сn���뷵�����������顣
 *
 *  ����������
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

		int l1 = 0;                                         //��һ�������������½�Ϊ0
		while (l1 + k <= n - 1) {
			l2 = l1 + k;                                    //����ڶ��������������½�
			u1 = l2 - 1;                                    //�����һ�������������Ͻ�
			u2 = (l2 + k - 1 <= n - 1) ? l2 + k - 1 : n - 1;//����ڶ��������������Ͻ�S

			//��������������ϲ�
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