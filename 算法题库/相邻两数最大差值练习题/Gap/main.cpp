/**
 * ��һ����������A�������һ�����Ӷ�ΪO(n)���㷨������������������������ֵ��
 *
 * ����һ��int����A��A�Ĵ�Сn���뷵�����Ĳ�ֵ����֤����Ԫ�ض���1����
 *
 * ����������
 * [1,2,5,4,6],5
 * ���أ�2
 */

#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Gap {
public:
	int maxGap(vector<int> A, int n) {
		// write code here
		if (n < 2)
			return 0;
		set<int> iset;
		for (const auto &i : A)
			iset.insert(i);
		auto pre = iset.begin();
		int max = 0;
		for (auto iter = ++iset.begin(); iter != iset.end(); ++iter)
		{
			if (*iter - *pre > max)
				max = *iter - *pre;
			++pre;
		}
		return max;
	}
};

int main() {
	int n;
	cin >> n;
	vector<int> A(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}

	class Gap gap;
	int max = gap.maxGap(A, n);
	cout << max << endl;

	system("pause");
	return 0;
}