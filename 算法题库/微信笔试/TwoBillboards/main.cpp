/*
一个页面有两个广告位，现有四个广告需要展示，实现一个算法输出需要展示的两个广告。
要求：
a.输出的两个广告不能相同；
b.多次调用输出的四个广告的概率为：1:2:3:4  （4个广告用整形1-4来表示）

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
3.逐行打印n * n回型矩阵（ 不可以在内存填好整个矩阵然后再打印）

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
int nSize;   // 矩阵维度，nSize*nSize;
int nHalfSize;
int nCircle; // 第几圈
int nEdge;   // 第几条边；
int nOffset; // 边上第几个值
int nBaseIndex; // 数值基数，当前圈基数+当前边基数
int GetNumber(int i, int j)
{
	// 根据ij判断第几圈
	nCircle = MIN(nSize, i);
	nCircle = MIN(nCircle, j);
	if (i >= nHalfSize) nCircle = MIN(nCircle, nSize - 1 - i);
	if (j >= nHalfSize) nCircle = MIN(nCircle, nSize - 1 - j);

	// 根据ij判断第几条边，顺时针顺序0~3
	// 同时计算偏移值；
	if (i > j)
	{
		// 左，下
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
		// 右，上
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

	// 计算数值
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
	// 输入
	cout << "请输入数组维度N，将输出N*N的蛇形矩阵：\n";
	cin >> nSize;
	nHalfSize = nSize / 2;
	cout << "打印矩阵如下：\n";

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
