/*
你只能在原队形上进行调整, 每次调整只能让相邻的两个小朋友交换位置, 
现在C和D 两种情况, 即, 问题变成将原字符串变为上述两种情况中移动次数最少
*/
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int Sort(string p, char a, char b) {
	int i = 0, j = 0;
	int nCount = 0;
	int numA = 0, tmpNum = 0;
	int len = p.length();

	for (i = 0; i<len; i++) {
		if (p[i] == a)
			numA++;
	}
	for (i = 0; i<len; i++) {
		j = i;
		if (p[i] == a) {
			tmpNum++;
			if (tmpNum == numA)
				break;
			continue;
		}
		else {
			while (p[j] != a) {
				j++;
			}
			tmpNum++;
			while (j>i) {
				swap(p[j], p[j - 1]);
				nCount++;
				j--;
			}
			if (tmpNum == numA)
				break;
		}
	}
	return nCount;
}

int main() {
	string p;
	int n = 0, m1 = 0, m2 = 0;
	cin >> p;

	m1 = Sort(p, 'C', 'D');
	m2 = Sort(p, 'D', 'C');

	n = min(m1, m2);

	cout << n << endl;

	system("pause");
	return 0;
}