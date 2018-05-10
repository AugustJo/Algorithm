/**
 * ��������С���������Ժ������A��B������A��ĩ�����㹻�Ļ��������B�����дһ����������B�ϲ���A������
 *
 * ������������int����A��B��A�еĻ������0��䣬ͬʱ����A��B����ʵ��Сint n��int m���뷵�غϲ�������顣
 *
 */
#include <iostream>
using namespace std;

class Merge {
public:
	int* mergeAB(int* A, int* B, int n, int m) {
		// write code here
		int i, j, k;
		i = n - 1;
		j = m - 1;
		k = n + m - 1;
		while (i >= 0 && j >= 0){
			if (A[i]<B[j]){
				A[k] = B[j];
				j--;
			}
			else{
				A[k] = A[i];
				i--;
			}

			k--;
		}
		while (j >= 0){
			A[k--] = B[j--];
		}

		return A;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	int *A = new int[m + n];
	int *B = new int[m];
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> B[i];
	}
	Merge merge;
	merge.mergeAB(A, B, n, m);
	for (int i = 0; i < n + m; ++i) {
		cout << A[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}