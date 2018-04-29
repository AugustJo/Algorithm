/**
 *  ����һ��int���飬���дһ��ϣ�������㷨��������Ԫ������
 *
 *  ����һ��int����A������Ĵ�Сn���뷵�����������顣��֤Ԫ��С�ڵ���2000��
 *
 *  ����������
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
		for (span = n / 2; span > 0; span = span / 2) {     //ϣ�����򲽳��������ܳ��ȿ�ʼ�ݼ�
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