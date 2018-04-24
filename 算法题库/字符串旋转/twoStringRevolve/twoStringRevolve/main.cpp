/**
 *	�������һ���ַ���A����A��ǰ������һ����Ų�����ȥ�γɵ��ַ�����ΪA����ת�ʡ�����A="12345",A����ת����"12345","23451","34512","45123"��"51234"��
 *	���������ַ���A��B�����ж�A��B�Ƿ�Ϊ��ת�ʡ�
 *
 *	���������ַ���A��B�����ǵĳ���lena��lenb���뷵��һ��boolֵ�����������Ƿ�Ϊ��ת�ʡ�
 *
 *	����������
 *	"cdab",4,"abcd",4
 *	���أ�true
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