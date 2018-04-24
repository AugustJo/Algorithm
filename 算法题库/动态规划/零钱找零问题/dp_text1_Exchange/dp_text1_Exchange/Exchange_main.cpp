#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Exchange {
public:
	int countWays(vector<int> penny, int n, int aim) {
		// write code here
		int res = 0;
		if(penny.empty() || n < 1 || aim < 0)
			return res;
		vector<vector<int> > dp(n, vector<int>(aim+1, 0));
		for(int i = 0; i < n; ++i)
			dp[i][0] = 1;            //目标钱数为0只有一种情况就是所有货币数目为0
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
	class Exchange exchange;
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
	numOfMethods = exchange.countWays(penny, n, aim);
	cout <<"The total number of methods to change is: "<<numOfMethods <<endl;
	system("pause");
	return 0;
}
