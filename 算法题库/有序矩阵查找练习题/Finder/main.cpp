/**
 * 现在有一个行和列都排好序的矩阵，请设计一个高效算法，快速查找矩阵中是否含有值x。
 *
 * 给定一个int矩阵mat，同时给定矩阵大小nxm及待查找的数x，请返回一个bool值，代表矩阵中是否存在x。所有矩阵中数字及x均为int范围内整数。保证n和m均小于等于1000。
 *
 * 测试样例：
 * [[1,2,3],[4,5,6],[7,8,9]],3,3,10
 * 返回：false
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
		while (row <= n - 1 && col >= 0)   //从矩阵右上角向左下角搜索
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