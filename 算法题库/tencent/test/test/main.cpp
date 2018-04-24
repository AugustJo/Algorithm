#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <map>

using namespace std;
/*
typedef struct task{
	int z;
	int w;
}TASK;

typedef struct machine{
	int x;
	int y;

}MACHINE;
int main(){
	int n,m;
	cin >> n>> m;
	vector<MACHINE> MA(n);
	vector<TASK> TA(m);
	for(int i=0; i < n; i++)
		cin >> MA[i].x >> MA[i].y;
	for(int i=0; i < m; i++)
		cin >> TA[i].z >> TA[i].w;

	cout << 1 << " "<< 20006;
	
	system("pause");
	return 0;
}
*/
/*
int comm(int n, int k){
	int res=1;
	for(int i=n; i >= n-k+1; i--)
		res *= i;
	for(int i=k; i>0; i--)
		res /= i;
	return res;
}

int main(){
	int K;
	cin >> K;
	int A, X, B, Y;
	cin >> A >> X >> B >> Y;

	int count = 0;
	int m;
	for(int i=1; i <= X;  ++i){
		if( (K-i*A) % B == 0){
			m = (K-i*A)/B;
			if(m <= Y)
				count += comm(Y,m) * comm(X,i);
		}
	}
	cout << count << endl;

	system("pause");
	return 0;
}
*/

int comm(int n, int k){
	int res=1;
	for(int i=n; i >= n-k+1; i--)
		res *= i;
	for(int i=k; i>0; i--)
		res /= i;
	return res;
}

int main(){
	int K;
	cin >> K;
	int A, X, B, Y;
	cin >> A >> X >> B >> Y;
	
	vector<vector<int> > dp(X+Y, vector<int>(K+1,0));
	for(int i=1; i <= K; ++i)
		if(i == A) dp[0][i] = 1;
	for(int i=0; i < X+Y; ++i){
		if(i < X && A <= 1)
			dp[i][1] = 1;
		else if(i >=X && A+B <=1)
			dp[i][1] = 1;
	}
	
	int numA,numB;
	for(int i=0; i < X+Y; ++i){
		for(int j=1; j <=K; ++j){
			if(i<X){
				if(K%A == 0){
					numA = K/A;
					if(numA <= i)
						dp[i][j] = dp[i-1][j] + comm(i, numA);
					else
						dp[i][j] = dp[i-1][j];
				}
			}
			else{
				if( K%A%B == 0 ){
					numA = K/A;
					numB = K%A/B;
					
				}
			}
		}
	}


	system("pause");
	return 0;
}

/*
int main(){
	long int n,m;
	cin >> n >> m;

	long int sum = 0;

	long int num2m = n/(2*m);
	long int deg = m; 
	sum = num2m * m * m;
	cout<<sum;

	system("pause");
	return 0;
}
*/

/*

struct Segment {
unsigned long int start, length;
};

int main(){

	string line;
	char* cline[1000];
	memset(cline, 0, sizeof(char)*1000 );
	char c;

	Segment temp;
	vector<Segment> vec;
	vector<vector<Segment>> segments;
	while(getline(cin,line)){ //Ctrl+z ÍË³ö
		istringstream strm(line);
		while(strm >> c){  // read '('
			strm >> temp.start;
			strm >> c;	   // read ','
			strm >> temp.length;
			strm >> c;	   // read ')'
			vec.push_back(temp);
		}
		segments.push_back(vec);
		vec.clear();
	}

	for(int i=0; i<segments.size(); ++i){
		for(int j=0; j<segments[i].size(); ++j)
			cout << '('<<segments[i][j].start<<','<<segments[i][j].length <<')';
		cout<<endl;
	}


	system("pause");
	return 0; 
}
*/
