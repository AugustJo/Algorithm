/**
 * ��n��̨�ף�һ����ÿ����һ���������������ж���������n��̨�׵ķ�����
 * Ϊ�˷�ֹ������뽫���Mod 1000000007
 * ����һ��������int n���뷵��һ������������¥�ķ�ʽ������֤nС�ڵ���100000��
 */
#include <iostream>
#include <vector>

using namespace std;

// �ݹ鱩������
class GoUpstairs_violence_search {
public:
	int countWays(int n) {
		if (n < 1)
			return 0;
		if (n == 1 || n == 2)
			return n;

		return countWays(n - 1) + countWays(n - 2);
	}
};


class GoUpstairs {
public:
	int countWays(int n) {
		// write code here
		if (n < 1)
			return 0;
		if (n == 1 || n == 2)
			return n;
		vector<int> vec(n, 0);
		vec[0] = 1;
		vec[1] = 2;
		for (int i = 2; i < n; ++i) {
			vec[i] = (vec[i - 1] + vec[i - 2]) % 1000000007;
		}
		return vec[n - 1];
	}
};

int main() {
	int n;
	cin >> n;
	GoUpstairs_violence_search GoUpstairs1; // ��������
	GoUpstairs GoUpstairs2; // ��̬�滮
	cout << "�������������" << GoUpstairs1.countWays(n) << endl;
	cout << "��̬�滮�����" << GoUpstairs2.countWays(n) << endl;

	system("pause");
	return 0;
}