/**
	��֪һ��������������飬����������ָ������������ź�˳��Ļ���ÿ��Ԫ���ƶ��ľ�����Բ�����k������k�����������˵�Ƚ�С����ѡ��һ�����ʵ������㷨���������ݽ�������

	����һ��int����A��ͬʱ����A�Ĵ�Сn�������е�k���뷵�����������顣

	����������
	[2,1,4,3,6,5,8,7,10,9],10,2
	���أ�[1,2,3,4,5,6,7,8,9,10]
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ScaleSort {
public:
	void creatHeap(vector<int> &a, int n, int h) {
		//������Ҷ�ڵ�a[h]ʹ֮����С���ѣ�nΪ����a��Ԫ�ظ���
		int i, j, flag;
		int temp;

		i = h;				//iΪҪ���ѵĶ��������ڵ��±�
		j = 2 * i + 1;		//jΪi�����ӽڵ��±�
		temp = a[i];
		flag = 0;

		//�����Һ�����ֵ��С���ظ�����ɸѡ
		while (j < n && flag != 1) {
			if (j < n - 1 && a[j] > a[j + 1]) ++j;

			if (temp < a[j])			//a[i]>a[j]
				flag = 1;			//��ǽ���ɸѡ����
			else {					//�����a[j]����
				a[i] = a[j];
				i = j;
				j = 2 * i + 1;
			}
		}
		a[i] = temp;				//�������a[i]��ֵ������a[j]
	}

	void initCreatHeap(vector<int> &a, int n) {
		//������Ԫ��a[0]~a[n-1]��ʼ������ΪС����
		for (int i = (n - 2) / 2; i >= 0; --i)
			creatHeap(a, n, i);
	}

	vector<int> sortElement(vector<int> &A, int n, int k) {
		// write code here
		//�߽���
		if (A.empty() || n < 1 || k < 0 || k > n)
			return A;

		//��ʼ��С����
		vector<int> minHeap(k);
		for (int i = 0; i < k; ++i) {
			minHeap[i] = A[i];
		}
		initCreatHeap(minHeap, k);

		//����С�������ǰn-k��ֵ
		for (int i = 0; i < n - k; ++i) {
			A[i] = minHeap[0];
			minHeap[0] = A[i + k];
			creatHeap(minHeap, k, 0);
		}

		//��ʣ���n - k��ֵʹ�ö�����
		for (int i = n - k; i < n; ++i) {
			A[i] = minHeap[0];
			minHeap[0] = minHeap[k - 1];
			creatHeap(minHeap, --k, 0);
		}

		return A;
	}
};

int main() {
	vector<int> A = { 2,1,4,3,6,5,8,7,10,9 };
	int n = 10;
	int k = 2;
	class ScaleSort scalesort;
	scalesort.sortElement(A, n, k);
	for (int i = 0; i < A.size(); ++i) {
		cout << A[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
