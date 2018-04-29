/**
 *  ����һ��int���飬���дһ���������㷨��������Ԫ������
 *
 *  ����һ��int����A������Ĵ�Сn���뷵�����������顣
 *
 *  ����������
 *  [1,2,3,5,2,3],6
 *  [1,2,2,3,3,5]
 */
#include <iostream>
using namespace std;

class HeapSort {
public:
	void creatHeap(int* a, int n, int h) {
		//������Ҷ�ڵ�a[h]ʹ֮�������ѣ�nΪ����a��Ԫ�ظ���
		int i, j, flag;
		int temp;

		i = h;              //iΪҪ���ѵĶ��������ڵ��±�
		j = 2 * i + 1;        //jΪi�����ӽڵ��±�
		temp = a[i];
		flag = 0;

		//�����Һ�����ֵ�ϴ����ظ�����ɸѡ
		while (j < n && flag != 1) {
			if (j < n - 1 && a[j] < a[j + 1]) ++j;

			if (temp > a[j])          //a[i]>a[j]
				flag = 1;           //��ǽ���ɸѡ����
			else {                   //�����a[j]����
				a[i] = a[j];
				i = j;
				j = 2 * i + 1;
			}
		}
		a[i] = temp;                //�������a[i]��ֵ������a[j]
	}

	void initCreatHeap(int* a, int n) {
		//������Ԫ��a[0]~a[n-1]��ʼ������Ϊ����
		for (int i = (n - 2) / 2; i >= 0; --i)
			creatHeap(a, n, i);
	}

	int* heapSort(int* A, int n) {
		if (A == NULL || n < 2)
			return A;

		int temp;
		initCreatHeap(A, n);

		for (int i = n - 1; i > 0; --i) {
			temp = A[0];
			A[0] = A[i];
			A[i] = temp;

			creatHeap(A, i, 0);
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
	HeapSort heap_sort;
	heap_sort.heapSort(A, n);
	for (int i = 0; i < n; ++i) {
		cout << A[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}