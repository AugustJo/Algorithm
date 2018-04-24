/**
 *	如果对于一个字符串A，将A的前面任意一部分挪到后边去形成的字符串称为A的旋转词。比如A="12345",A的旋转词有"12345","23451","34512","45123"和"51234"。
 *	对于两个字符串A和B，请判断A和B是否互为旋转词。
 *
 *	给定两个字符串A和B及他们的长度lena，lenb，请返回一个bool值，代表他们是否互为旋转词。
 *
 *	测试样例：
 *	"cdab",4,"abcd",4
 *	返回：true
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Rotation {
public:
	void GetNext(string &T, int length, vector<int> next) {
		int j = 1, k = 0;

		next[0] = -1;
		next[1] = 0;
		while (j < length - 1) {
			if (T[j] == T[k]) {
				next[j + 1] = k + 1;
				++j;
				++k;
			}
			else if (k == 0) {
				next[j + 1] = 0;
				++j;
			}
			else k = next[k];
		}
	}

	bool chkRotation(string A, int lena, string B, int lenb) {
		if (lena != lenb)
			return false;

		vector<int> next(lenb);
		GetNext(B, lenb, next);
		string longA = A + A;

		int lenaa = lena + lena;
		int i = 0, j = 0;
		int v;
		while (i < lenaa && j < lenb) {
			if (longA[i] == B[j]) {
				++i;
				++j;
			}
			else if (j == 0) i++;
			else j = next[j];
		}

		if (j == lenb) return true;
		else return false;
	}
};

int main() {
	string A("cdab");
	string B("abcd");
	Rotation R;
	bool res = R.chkRotation(A, A.length(), B, B.length());
	if (true == res)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	system("pause");
	return 0;
}