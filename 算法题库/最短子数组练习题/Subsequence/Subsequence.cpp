/**
 * ����һ�����飬�����һ����Ч�㷨������Ҫ��������������ĳ��ȡ�
 *
 * ����һ��int����A������Ĵ�Сn���뷵��һ����Ԫ�飬�����������еĳ��ȡ�(ԭ����λ�ô�0��ʼ���, ��ԭ�������򣬷���0)����֤A��Ԫ�ؾ�Ϊ��������
 *
 * ����������
 * [1, 4, 6, 5, 9, 10], 6
 * ���أ�2
 */

#include <vector>
#include <iostream>

using namespace std;

class Subsequence {
public:
	int shortestSubsequence(vector<int> A, int n) {
		// write code here
		if (n <= 1)return 0;
		int left = 0;
		int right = n - 1;
		int max = A[0];
		int min = A[n - 1];
		int count = 0;
		for (int i = 0; i<n; i++)
		{
			if (max <= A[i])
			{
				max = A[i];
			}
			else left = i;
		}
		for (int i = n - 1; i >= 0; i--)
		{
			if (min >= A[i])
			{
				min = A[i];
			}
			else right = i;
		}
		return (left - right)>0 ? (left - right + 1) : 0;
	}
};

int main() {
	int n;
	cin >> n;
	//int* temp = new int[n](); // �������ţ�ȫ����
	vector<int> A(n,0);
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}

	class Subsequence subsequence;
	int shortSubsequence = subsequence.shortestSubsequence(A, n);
	cout << shortSubsequence << endl;

	system("pause");
	return 0;
}
