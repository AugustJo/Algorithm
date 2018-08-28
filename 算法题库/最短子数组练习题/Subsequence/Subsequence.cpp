/**
 * 对于一个数组，请设计一个高效算法计算需要排序的最短子数组的长度。
 *
 * 给定一个int数组A和数组的大小n，请返回一个二元组，代表所求序列的长度。(原序列位置从0开始标号, 若原序列有序，返回0)。保证A中元素均为正整数。
 *
 * 测试样例：
 * [1, 4, 6, 5, 9, 10], 6
 * 返回：2
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
	//int* temp = new int[n](); // 最后的括号，全置零
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
