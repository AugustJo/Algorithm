/**
 * ��һ��ֻ��0��1��2����Ԫ�ع��ɵ��������飬��ʹ�ý�����ԭ�����������ʹ�ü�����������
 *
 * ����һ��ֻ��0��1��2����������A�����Ĵ�С���뷵�����������顣��֤�����СС�ڵ���500��
 *
 * ����������
 * [0,1,1,0,2,2],6
 * ���أ�[0,0,1,1,2,2]
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ThreeColor {
public:
	vector<int> sortThreeColor(vector<int> A, int n) {
		// write code here
		int low = 0, high = n - 1;
		for (int i = 0; i <= high; i++) {
			if (A[i] == 0) {
				swap(A[i], A[low]);
				low++;
			}
			else if (A[i] == 2) {
				swap(A[i], A[high]);
				high--;
				i--;
			}
		}
		return A;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	ThreeColor sort;
	A = sort.sortThreeColor(A, n);
	for (int i = 0; i < n; ++i) {
		cout << A[i] <<' ';
	}
	cout << endl;

	system("pause");
	return 0;
}