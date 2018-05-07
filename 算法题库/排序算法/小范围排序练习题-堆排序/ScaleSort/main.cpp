/**
	已知一个几乎有序的数组，几乎有序是指，如果把数组排好顺序的话，每个元素移动的距离可以不超过k，并且k相对于数组来说比较小。请选择一个合适的排序算法针对这个数据进行排序。

	给定一个int数组A，同时给定A的大小n和题意中的k，请返回排序后的数组。

	测试样例：
	[2,1,4,3,6,5,8,7,10,9],10,2
	返回：[1,2,3,4,5,6,7,8,9,10]
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ScaleSort {
public:
	void creatHeap(vector<int> &a, int n, int h) {
		//调整非叶节点a[h]使之满足小根堆，n为数组a的元素个数
		int i, j, flag;
		int temp;

		i = h;				//i为要建堆的二叉树根节点下标
		j = 2 * i + 1;		//j为i的左孩子节点下标
		temp = a[i];
		flag = 0;

		//沿左右孩子中值较小者重复向下筛选
		while (j < n && flag != 1) {
			if (j < n - 1 && a[j] > a[j + 1]) ++j;

			if (temp < a[j])			//a[i]>a[j]
				flag = 1;			//标记结束筛选条件
			else {					//否则把a[j]上移
				a[i] = a[j];
				i = j;
				j = 2 * i + 1;
			}
		}
		a[i] = temp;				//把最初的a[i]赋值给最后的a[j]
	}

	void initCreatHeap(vector<int> &a, int n) {
		//把数组元素a[0]~a[n-1]初始化创建为小根堆
		for (int i = (n - 2) / 2; i >= 0; --i)
			creatHeap(a, n, i);
	}

	vector<int> sortElement(vector<int> &A, int n, int k) {
		// write code here
		//边界检测
		if (A.empty() || n < 1 || k < 0 || k > n)
			return A;

		//初始化小根堆
		vector<int> minHeap(k);
		for (int i = 0; i < k; ++i) {
			minHeap[i] = A[i];
		}
		initCreatHeap(minHeap, k);

		//利用小根堆求出前n-k个值
		for (int i = 0; i < n - k; ++i) {
			A[i] = minHeap[0];
			minHeap[0] = A[i + k];
			creatHeap(minHeap, k, 0);
		}

		//对剩余的n - k个值使用堆排序
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
