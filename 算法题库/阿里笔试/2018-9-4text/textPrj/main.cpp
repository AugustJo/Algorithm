/*#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>

using namespace std;

string sum(string, string, string, string);

bool main()
{
	string num1, num2;
	cin >> num1 >> num2;
	string num11, num12, num21, num22;
	//������
	//�Ƿ���С���ı�־
	bool num1Flag = false, num2Flag = false;
	for (auto c : num1)
	{
		//�����ֻ������ּ�һ��.���
		if (!isdigit(c) || num1.empty())
		{
			if (c == '.' && !num1Flag)
			{
				num1Flag = true;
			}
			else
			{
				cout << "false """ << endl;
				system("pause");
				return false;
			}
		}
	}
	for (auto c : num2)
	{
		if (!isdigit(c) || num2.empty())
		{
			if (c == '.' && !num2Flag)
			{
				num2Flag = true;
			}
			else
			{
				cout << "false """ << endl;
				system("pause");
				return false;
			}
		}
	}

	//�ַ����ָ�{�������ֺ�С������)
	if (num1Flag)//�����С��
	{
		int i = 0;
		while (i != num1.size() && num1[i] != '.')
		{
			num11 += num1[i];
			++i;
		}
		while (++i != num1.size())
		{
			num12 += num1[i];
		}
		//����.XXX��XXX.������Ŀ���
		if (num11.empty())
			num11 += '0';
		if (num12.empty())
			num12 += '0';
	}

	else//���������
	{
		num11 = num1;
		num12 += '0';
	}
	if (num2Flag)//�����С��
	{
		int i = 0;
		while (i != num2.size() && num2[i] != '.')
		{
			num21 += num2[i];
			++i;
		}
		while (++i != num2.size())
		{
			num22 += num2[i];
		}
		//����.XXX��XXX.������Ŀ���
		if (num21.empty())
			num21 += '0';
		if (num22.empty())
			num22 += '0';
	}
	else//���������str
	{
		num21 = num2;
		num22 += '0';
	}

	cout << "true " << sum(num11, num12, num21, num22) << endl;

	system("pause");
	return true;
}


//�ӷ�  �ϳ����������� �ϳ���С������ �϶̵��������� �϶̵�С������
string sum(string strLong1, string strLong2, string strShort1, string strShort2)
{
	//С�����ּ���
	if (strLong2.size()<strShort2.size())
	{
		string strTemp = strLong2;
		strLong2 = strShort2;
		strShort2 = strTemp;
	}
	//��0
	for (int i = strShort2.size(); i<strLong2.size(); ++i)
		strShort2 += '0';
	//��ת�ַ���
	reverse(strLong2.begin(), strLong2.end());
	reverse(strShort2.begin(), strShort2.end());
	//С�����ֽ��мӷ�����
	string strRes2(strLong2.size(), '0');
	int carry = 0;//��λ
	for (int i = 0; i != strLong2.size(); ++i)
	{
		int a = strShort2[i] - '0', b = strLong2[i] - '0';
		a = a + b + carry;
		carry = a / 10;
		strRes2[i] = (a % 10) + '0';
	}
	//��ת����
	reverse(strRes2.begin(), strRes2.end());


	//�������ּ���
	if (strLong1.size()<strShort1.size())
	{
		string strTemp = strLong1;
		strLong1 = strShort1;
		strShort1 = strTemp;
	}
	//��ת�ַ���
	reverse(strLong1.begin(), strLong1.end());
	reverse(strShort1.begin(), strShort1.end());


	string strRes1(strLong1.size(), '0');
	for (int i = 0; i != strShort1.size(); ++i)
	{
		int a = strShort1[i] - '0', b = strLong1[i] - '0';
		a = a + b + carry;
		carry = a / 10;
		strRes1[i] = (a % 10) + '0';
	}
	for (int i = strShort1.size(); i != strLong1.size(); ++i)
	{
		int b = strLong1[i] - '0';
		b += carry;
		carry = b / 10;
		strRes1[i] = b % 10 + '0';
	}
	if (carry)
	{
		strRes1 += (carry + '0');
	}
	//��ת����
	reverse(strRes1.begin(), strRes1.end());

	//�ϲ��������ֺ�С������
	string strRes = strRes1 + '.' + strRes2;
	return strRes;
}
*/

// �ĸ����ӵĺ�ŵ�����⣺
// https://blog.csdn.net/qq_34576910/article/details/53574866
//
/*
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
using namespace std;

void deal(double *a)
{
	a[0] = 0;
	a[1] = 1;
	a[2] = 3;
	for (int n = 3; n <= 64; n++)
	{
		double min = 0xfffffff;
		double tmp;
		for (int k = 1; k < n; k++)
		{
			tmp = 2 * a[k] + pow(2, n - k) - 1;
			if (tmp < min)
				min = tmp;
		}
		a[n] = min;
	}
}

int main()
{
	double num[70];
	int n;
	deal(num);
	while (cin>>n)
	{
		cout << num[n] << endl;
	}
	return 0;
}
*/


/*
���ڼ�������һ��������M��Partition�����Ϊ(0,1,2��M-1)��ͬʱ��һ����СΪM������partition_size_array����ÿ����Ƭ�Ĵ�С������[100,110,120,130]����ʾP0.size=100,P1.size=110�� ÿ��Partition��3������������������䵽��N(N>3)���ڵ��ϣ���һ��������ά����node_replica_table(size=N)������ǰÿ���ڵ�����Partition���:
node_replica_table[0] = {0, 1, 5} ; // node0������partition0, partition1, partition5;
node_replica_table[1] = {1, 2, 3}; // node1������partition1, partition2, partition3;
..
node_repliac_table[N-1] = {��};


Ҫ���дһ������������Ҫ�ﵽ���ؾ����������СǨ�Ʋ���(ÿ�ο����ƶ�һ��partition��һ���ڵ㵽��һ���ڵ�)����������Ǹ��ؾ��⣬��ô����0������޷����㣬����-1.

����:
�������ݰ���N+2�У�
��һ��Ϊ N M D
�ڶ���Ϊ partition_size_array, ��Сreplica����M(M>N)
ʣ��M��Ϊnode_replica_table��ÿһ�б�ʾһ��node�ϵ�replia���飬��СΪС��M+1��������������һ����������Ĵ�С������ÿ�������Ԫ���Ǹ����ı�ţ�Ҳ����partition_size_array���±�
���:
��СǨ�Ʋ���
���뷶��:
5 6 100
100 110 120 130 140 150
6 0 1 2 3 4 5
5 0 1 2 3 4
4 0 2 4 5
2 1 5
1 3
�������:
2

*/
/*
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>

using namespace std;

// ������������������ʵ����ĿҪ��Ĺ��� 
// ��Ȼ����Ҳ���Բ��������ģ����������ȫ�����Լ����뷨�� ^-^  
int rebalance(vector < vector < int > > node_replica_table, vector < int > partition_size_array, int threshold) {
	vector<int> node_replica_table_weight(node_replica_table.size(), 0);

	for (int i = 0; i < node_replica_table.size(); ++i) {
		for (int j = 0; j < node_replica_table[i].size(); ++j) {
			node_replica_table_weight[i] += partition_size_array[node_replica_table[i][j]];
		}
	}

	sort(node_replica_table_weight.begin(), node_replica_table_weight.end());

	int small = node_replica_table_weight[0];
	int big = node_replica_table_weight[node_replica_table_weight.size() - 1];
	int hashtableNum = (big - small) / threshold;
	int *hashtable = new int[hashtableNum];
	memset(hashtable, 0, hashtableNum * sizeof(int));

	for (int i = 0; i < node_replica_table_weight.size(); ++i) {
		hashtable[(node_replica_table_weight[i] - small) / threshold]++;
	}

	int stepNum = 0;
	for (int i = 0; i < hashtableNum; ++i) {
		if (hashtable[i] == 0)
			stepNum++;
	}

	return stepNum;
}

int main(int argc, char **argv)
{
	int node_num = 0, replica_num = 0, threshold = 0;
	cin >> node_num >> replica_num >> threshold;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	vector<int> replica_size_array;
	int replica_size = 0;
	for (int i = 0; i < replica_num; ++i) {
		cin >> replica_size;
		replica_size_array.push_back(replica_size);
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	vector<vector<int>> node_replica_table;
	vector<int> node_replica;
	int replica_index = 0;
	for (int i = 0; i < node_num; ++i) {
		cin >> replica_num;
		node_replica.clear();
		for (int j = 0; j < replica_num; ++j) {
			cin >> replica_index;
			node_replica.push_back(replica_index);
		}
		node_replica_table.push_back(node_replica);
	}

	int r = rebalance(node_replica_table, replica_size_array, threshold);
	std::cout << r << std::endl;

	system("pause");

	return 0;
}
*/


#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int SIZE = 1e5 + 5;
typedef long long ll;
ll dp[SIZE] = { 0 };

int main(void)
{
	ios::sync_with_stdio(false);
	string p_s, t_s;
	unordered_map<string, bool> vis;
	unordered_map<string, bool> rvis;
	cin >> p_s;
	int n;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> t_s;
		rvis[t_s] = true;
		reverse(t_s.begin(), t_s.end());
		vis[t_s] = true;
	}
	int len = p_s.size();
	dp[len] = 1;

	for (int i = len; i >= 0; i--)
	{
		if (dp[i] == 0) continue;
		string tem_s;
		for (int j = 1; i - j >= 0 && j <= 50; j++)
		{
			tem_s += p_s[i - j];
			if (vis[tem_s])
			{
				dp[i - j] = max(dp[i - j], dp[i] + j * j);
			}
		}
	}
	vector<string> ans;
	for (int i = 0; i<len; i++)
	{
		string tem_s, ans_s;
		int p = i;
		for (int j = 1; j <= 50 && i + j <= len; j++)
		{
			tem_s += p_s[i + j - 1];

			if (rvis[tem_s])
			{
				if (dp[i] == (j*j + dp[i + j]))
				{
					ans_s = tem_s;
					p = i + j;
				}
			}
		}i = p - 1;
		ans.push_back(ans_s);
	}
	for (int i = 0; i<ans.size(); i++)
	{
		cout << ans[i];
		if (i == ans.size() - 1) cout << endl;
		else cout << " ";
	}
	system("pause");
	return 0;
}


