#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/**
 * ��Ǯ���������������ܽ�
 *
 */

//�㷨һ����������
class Exchange_violence_search {
public:
	int countWays(vector<int> penny, int n, int aim) {
		if (penny.empty() || n < 1 || aim < 0)
			return 0;

		return process1(penny, 0, aim);

	}

	int process1(vector<int> penny, int index, int aim) {
		int res = 0;
		if (index == penny.size()) {
			res = (aim == 0) ? 1 : 0;
		}
		else {
			for (int i = 0; penny[index] * i <= aim; ++i) {
				res += process1(penny, index + 1, aim - penny[index] * i);
			}
		}

		return res;
	}
};

// �㷨�������仯���������м�ļ������洢��һ��map�У��´ν��еݹ�֮ǰ�ȼ��map���Ƿ��м�¼��
// �о�ֱ���ã�û�оͽ��еݹ飬��������ٴα��浽map�С�
class Exchange_memory_search {
public:
	int countWays(vector<int> penny, int n, const int aim) {
		if (penny.empty() || n < 1 || aim < 0)
			return 0;

		vector<vector<int> > map(penny.size() + 1, vector<int>(aim + 1));
		return process2(penny, 0, aim, map);
	}

	int process2(vector<int> arr, int index, int aim, vector<vector<int> > map) {
		int res = 0;
		if (index == arr.size()) {
			res = (aim == 0) ? 1 : 0;
		}
		else {
			int mapValue = 0;
			for (int i = 0; arr[index] * i <= aim; ++i) {
				mapValue = map[index + 1][aim - arr[index] * i];
				if (mapValue != 0) {
					res += (mapValue == -1) ? 0 : mapValue;
				}
				else {
					res += process2(arr, index + 1, aim - arr[index] * i, map);
				}
			}
		}
		map[index][aim] = (res == 0) ? -1 : res;
		return res;
	}
};

class Exchange {
public:
	int countWays(vector<int> penny, int n, int aim) {
		// write code here
		int res = 0;
		if(penny.empty() || n < 1 || aim < 0)
			return res;
		vector<vector<int> > dp(n, vector<int>(aim+1, 0));
		for(int i = 0; i < n; ++i)
			dp[i][0] = 1;            //Ŀ��Ǯ��Ϊ0ֻ��һ������������л�����ĿΪ0
		for(int i = 1; i < aim + 1; ++i)
			if(i % penny[0] == 0)
				dp[0][i] = 1;

		for(int i = 1; i < n; ++i){
			for(int j = 1; j < aim + 1; ++j){
				if(j - penny[i] >= 0)
					dp[i][j] = dp[i][j - penny[i]]+ dp[i-1][j];
				else
					dp[i][j] = dp[i-1][j];
			}
		}

		res = dp[n-1][aim];
		return res;
	}
};

int main(){
	Exchange_violence_search exchange1;
	Exchange_memory_search exchange2;
	Exchange exchange;
	vector<int> penny;
	int n;
	int aim;
	cout << "Please enter the number of change:" << endl;
	cin >> n;
	penny.reserve(n);
	cout << "Please enter "<< n <<" kinds of change in turn:"<<endl;
	int temp;
	for(int i=0; i < n; ++i){
		cin >> temp;
		penny.push_back(temp);
	}
	cout << "Please enter the total amount:"<<endl;
	cin >> aim;

	int numOfMethods;
	numOfMethods = exchange1.countWays(penny, n, aim); // ���������㷨
	cout << "���������㷨���: " << numOfMethods << endl;
	numOfMethods = exchange2.countWays(penny, n, aim); // ���������㷨
	cout << "���������㷨���: " << numOfMethods << endl;
	numOfMethods = exchange.countWays(penny, n, aim);  // dp
	cout << "��̬�滮�㷨���: " << numOfMethods << endl;
	//cout <<"The total number of methods to change is: "<<numOfMethods <<endl;
	system("pause");
	return 0;
}
