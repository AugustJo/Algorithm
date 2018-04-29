/**
 ����һ��int���飬���дһ�����������㷨��������Ԫ������

 ����һ��int����A������Ĵ�Сn���뷵�����������顣��֤Ԫ�ؾ�С�ڵ���2000��

 ����������
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