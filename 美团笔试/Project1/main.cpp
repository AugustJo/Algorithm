/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;


const int maxn = 110;
const int inf = 1000000;

int dist[maxn][maxn];
int e[maxn][maxn];

int n, m;

void initial() {
	int i;
	int j;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			if (i == j) {
				e[i][j] = 0;
			}
			else {
				e[i][j] = inf;
			}
		}
	}
}


int floyd() {
	int i;
	int j;
	int k;

	int mincircle = inf;
	//	dist = e;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			dist[i][j] = e[i][j];
		}
	}

	//根据Floyed的原理，在最外层循环做了k-1次之后，dis[i][j]则代表了i到j的路径中所有结点编号都小于k的最短路径
	for (k = 1; k <= n; ++k) {

		//环的最小长度为edge[i][k]+edge[k][j]+i->j的路径中所有编号小于k的最短路径长度
		for (i = 1; i < k; ++i) {
			for (j = i + 1; j < k; ++j) {
				if (dist[i][j] + e[i][k] + e[k][j] < inf) {
					mincircle = min(mincircle, dist[i][j] + e[j][k] + e[k][i]);
				}
			}
		}


		//floyd原来的部分,更新dist[i][j]
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	return mincircle;
}


int main() {
	cin >> n;
	m = n - 1;
	initial();

	int i;
	for (i = 1; i <= m; ++i) {
		int a;
		int b;
		int c = 1;
		//scanf("%d%d%d", &a, &b, &c);
		cin >> a >> b;

		if (e[a][b] > c) {
			e[a][b] = e[b][a] = c;
		}
	}

	int ans = floyd();
	if (ans != inf) {
		printf("%d\n", ans);
	}
	else {
		printf("It's impossible.\n");
	}

	system("pause");
	return 0;
}
*/

#include <iostream>

using namespace std;

int a[100][100], vis[100], n, e;
int num = 0;
void dfs(int x)
{
	vis[x] = 1;
	//cout << " " << x;
	num++;
	for (int i = 0; i<n; i++)
		if (a[x][i] && !vis[i])
		{
			dfs(i);
		}
}
int main()
{
	cin >> n;
	e = n - 1;

	for (int i = 0, u, v; i < e; i++)
		cin >> u >> v, a[u][v] = 1, a[v][u] = 1;
	for (int i = 0; i < n; i++)
		if (!vis[i])
			dfs(i);

	cout << num << endl;

	system("pause");
	return 0;
}
