/**
 * ������һ���к��ж��ź���ľ��������һ����Ч�㷨�����ٲ��Ҿ������Ƿ���ֵx��
 *
 * ����һ��int����mat��ͬʱ���������Сnxm�������ҵ���x���뷵��һ��boolֵ������������Ƿ����x�����о��������ּ�x��Ϊint��Χ����������֤n��m��С�ڵ���1000��
 *
 * ����������
 * [[1,2,3],[4,5,6],[7,8,9]],3,3,10
 * ���أ�false
 */
#include <iostream>
#include <vector>
using namespace std;

class Finder {
public:
	bool findX(vector<vector<int> > mat, int n, int m, int x) {
		// write code here
		int row = 0;
		int col = m - 1;
		while (row <= n - 1 && col >= 0)   //�Ӿ������Ͻ������½�����
		{
			if (x == mat[row][col]) { return true; }
			if (x < mat[row][col])
			{
				col--;
			}
			else {
				row++;
			}
		}
		return false;
	}
};

int main() {
	int n, m, x;
	cin >> n >> m >> x;
	vector<vector<int> > mat(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> mat[i][j];
		}
	}
	Finder finder;
	cout << boolalpha << finder.findX(mat, n, m, x) << endl;

	system("pause");
	return 0;
}