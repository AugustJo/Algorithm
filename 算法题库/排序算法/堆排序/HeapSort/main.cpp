/**
 *  对于一个int数组，请编写一个堆排序算法，对数组元素排序。
 *
 *  给定一个int数组A及数组的大小n，请返回排序后的数组。
 *
 *  测试样例：
 *  [1,2,3,5,2,3],6
 *  [1,2,2,3,3,5]
 */
#include <iostream>
using namespace std;

class HeapSort {
public:
	void creatHeap(int* a, int n, int h) {
		//调整非叶节点a[h]使之满足最大堆，n为数组a的元素个数
		int i, j, flag;
		int temp;

		i = h;              //i为要建堆的二叉树根节点下标
		j = 2 * i + 1;        //j为i的左孩子节点下标
		temp = a[i];
		flag = 0;

		//沿左右孩子中值较大者重复向下筛选
		while (j < n && flag != 1) {
			if (j < n - 1 && a[j] < a[j + 1]) ++j;

			if (temp > a[j])          //a[i]>a[j]
				flag = 1;           //标记结束筛选条件
			else {                   //否则把a[j]上移
				a[i] = a[j];
				i = j;
				j = 2 * i + 1;
			}
		}
		a[i] = temp;                //把最初的a[i]赋值给最后的a[j]
	}

	void initCreatHeap(int* a, int n) {
		//把数组元素a[0]~a[n-1]初始化创建为最大堆
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