/*
һ��ҳ�����������λ�������ĸ������Ҫչʾ��ʵ��һ���㷨�����Ҫչʾ��������档
Ҫ��
a.�����������治����ͬ��
b.��ε���������ĸ����ĸ���Ϊ��1:2:3:4  ��4�����������1-4����ʾ��

int res[2]={0};

void getad(int[] res) {

}
*/
/*
#include <iostream>
#include <vector>

using namespace std;

int res[2] = { 0 };

void getad(int* res) {
	int buff[10] = { 1,2,2,3,3,3,4,4,4,4 };
	int N = rand() % 10;
	res[0] = buff[N];
	int n = rand() % 10;
	while (buff[n] == buff[N]) {
		n = rand() % 10;
	}
	res[1] = buff[n];
}

int main() {
	getad(res);
	cout << res[0] << ' ' << res[1] << endl;

	system("pause");
	return 0;
}
*/


/*
3.���д�ӡn * n���;��� ���������ڴ������������Ȼ���ٴ�ӡ��

n=3
1 2 3
8 9 4
7 6 5

n=4
1 2 3 4
12 13 14 5
11 16 15 6
10 9 8 7

*/
//#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MIN(a,b) ( (a)<(b) ? (a):(b))
int nSize;   // ����ά�ȣ�nSize*nSize;
int nHalfSize;
int nCircle; // �ڼ�Ȧ
int nEdge;   // �ڼ����ߣ�
int nOffset; // ���ϵڼ���ֵ
int nBaseIndex; // ��ֵ��������ǰȦ����+��ǰ�߻���
int GetNumber(int i, int j)
{
	// ����ij�жϵڼ�Ȧ
	nCircle = MIN(nSize, i);
	nCircle = MIN(nCircle, j);
	if (i >= nHalfSize) nCircle = MIN(nCircle, nSize - 1 - i);
	if (j >= nHalfSize) nCircle = MIN(nCircle, nSize - 1 - j);

	// ����ij�жϵڼ����ߣ�˳ʱ��˳��0~3
	// ͬʱ����ƫ��ֵ��
	if (i > j)
	{
		// ����
		if (j == nCircle)
		{
			nEdge = 3;
			nOffset = nSize - 1 - nCircle - i;
		}
		else
		{
			nEdge = 2;
			nOffset = nSize - 1 - nCircle - j;
		}
	}
	else
	{
		// �ң���
		if (i == nCircle)
		{
			nEdge = 0;
			nOffset = j - nCircle;
		}
		else
		{
			nEdge = 1;
			nOffset = i - nCircle;
		}
	}

	// ������ֵ
	nBaseIndex = 0;
	for (int k = 0; k < nCircle; k++)
	{
		nBaseIndex += 4 * (nSize - 1 - 2 * k);
	}
	nBaseIndex += (nSize - 1 - 2 * nCircle) * nEdge;

	return nBaseIndex + nOffset + 1;
}

int main()
{
	// ����
	cout << "����������ά��N�������N*N�����ξ���\n";
	cin >> nSize;
	nHalfSize = nSize / 2;
	cout << "��ӡ�������£�\n";

	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			cout << GetNumber(i, j) << " ";
		}
		cout << "\n";
	}

	system("pause");
	return 0;
}
