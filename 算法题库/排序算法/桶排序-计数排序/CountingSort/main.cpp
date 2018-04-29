/**
 * ����һ��int���飬���дһ�����������㷨��������Ԫ������
 *
 * ����һ��int����A������Ĵ�Сn���뷵�����������顣
 *
 * ����������
 * [1,2,3,5,2,3],6
 * [1,2,2,3,3,5]
 *
 */
#include <iostream>
#include <vector>
using namespace std;

class CountingSort {
public:
	int* countingSort(int* A, int n) {
		if (A == NULL || n < 2)
			return A;
		int max = 0, min = A[0];

		for (int i = 0; i < n; ++i) {
			if (A[i] > max) max = A[i];
			if (A[i] < min) min = A[i];
		}
		int len = max - min + 1;
		vector<vector<int> > res(len);
		for (int i = 0; i < n; ++i) {
			res[A[i] - min].push_back(A[i]);
		}
		int count = 0;
		for (int i = 0; i < len; i++) {
			if (!res[i].empty()) {
				for (vector<int>::iterator itr = res[i].begin(); itr != res[i].end(); ++itr) {
					A[count++] = *itr;
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
	CountingSort count_sort;
	count_sort.countingSort(A, n);
	for (int i = 0; i < n; ++i) {
		cout << A[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}