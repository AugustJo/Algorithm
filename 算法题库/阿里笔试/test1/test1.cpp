#include <iostream>
#include<sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <map>


using namespace std;

int main(){
	int n;
	cin >> n;
	int res=1;
	int countTree=0;
	int relese=0;

	if(n < 2)
		cout<< 0;
	else if(n < 4)
		cout<< n-1;
	else{
		countTree = n/3;
		relese = n%3;
		if(relese==1){
			countTree--;
			relese = 4;
		}
		for(int i=0; i < countTree; i++){
			res *=3;
		}
		if(relese != 0)
			res *= relese;
		cout << res;
	}

	system("pause");
	return 0;
}
/*
int main(){
	int n;
	cin >> n;
	stack<char> stkLeft;
	stack<char> stkRight;
	for(int i=0; i < n; i++)
		stkLeft.push('(');

	if(n==1){
		cout << "()";
		//return 0;
	}
	if(n==2){
		cout<<"(()),()()";
		//return 0;
	}


	//for(int i=n; i > 0 && !stkLeft.empty(); --i){
	//	for(int k=0; k < n; k++)
	//		stkLeft.push('(');

	//	for(int j=i;j>0;--j){
	//		cout<<stkLeft.top();
	//		stkLeft.pop();
	//		stkRight.push(')');
	//	}
	//	while(!stkRight.empty() || !stkLeft.empty()){
	//		while(!stkRight.empty()){
	//			cout<<stkRight.top();
	//			stkLeft.pop();
	//		}
	//		while(!stkLeft.empty()){
	//			cout<<stkLeft.top();
	//			stkLeft.pop();
	//			stkRight.push(')');
	//		}
	//	}
	//	if(i > 1)
	//		cout<<',';
	//}


	system("pause");
	return 0;
}
*/


/*
int main(){
	string str;
	cin >> str;
	bool flag = false;
	int longest=0;
	for(int i=1; i < str.length(); ++i){
		int len = i;
		string temp;
		while(temp.length() < str.length()){
			temp += str.substr(0,len);
		}
		if(temp == str){
			flag = true;
			if(len > longest)
				longest = len;
			//break;
		}
	}
	if(flag == true){
		cout << str.substr(0,longest);
	}
	else{
		cout<< "false";
	}

	system("pause");
	return 0;
}
*/
/*
typedef long long int64_t;

struct Segment {
	int64_t start, length;
};
enum s{
	Start = 0,
	LeftBracket = 1,
	Comma = 2,
	RightBracket = 3
};
void input(vector<vector<Segment>>& segments)
{
	// write your cool code here
	string line;
	char* cline[1000];
	memset(cline, 0, sizeof(char)*1000 );
	Segment temp;
	vector<Segment> vec;
	enum s  state = Start;
	char c;
	cout<<"Now you can input as many lines of words as you wish."<<endl;
	cout<<"For example:(1,2)(3,4)..."<<endl;
	cout<<"To terminate, please press Ctrl+z:\n";
	while(getline(cin,line)){
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
}

vector<Segment> merge(vector<vector<Segment>> segments) 
{
	// write your cool code here
	vector<char> vec;
	char flag = 'A';
	for(int i=0; i<segments.size(); ++i){
		int start = 0;
		int length = 0;
		if(i==0){		// First one highest priority
			for(int j=0; j < segments[i].size(); ++j){
				length = segments[i][j].start;
				for(int k=start; k<length; ++k)
					vec.push_back('0');

				start = segments[i][j].start;
				length = segments[i][j].start + segments[i][j].length;
				for(int k=start; k<length; ++k)
					vec.push_back(flag);

				start = segments[i][j].start + segments[i][j].length;
			}
		}
		else{
			++flag; //next flag
			for(int j=0; j < segments[i].size(); ++j){
				length = segments[i][j].start;
				for(int k=start; k<length; ++k){
					if(k >= vec.size()){
						vec.push_back('0');
					}
				}

				start = segments[i][j].start;
				length = segments[i][j].start + segments[i][j].length;
				for(int k=start; k<length; ++k){
					if(k >= vec.size()){
						vec.push_back(flag);
					}
					else if(vec[k] == '0')
						vec[k] = flag;
				}

				start = segments[i][j].start + segments[i][j].length;
			}
		}
	}

	for(int i=0; i<vec.size();i++){
		cout<<vec[i]<<' ';
	}
	cout<<endl;

	Segment temp;
	vector<Segment> res;
	int count = 0;
	char lastFlag=0;
	char currentFlag=0;
	int firstDetect = 0;
	for(int i=0; i < vec.size(); ++i){
		if(vec[i] != '0'){
			currentFlag = vec[i];
			if(lastFlag != currentFlag && firstDetect == 0){
				firstDetect = 1;

				count = 1;
				temp.start = i;
			}
			else if(lastFlag != currentFlag){
				temp.length = count;
				res.push_back(temp);

				count = 1;
				temp.start = i;
			}
			else{
				++count;
			}
			lastFlag = currentFlag;
		}
	}
	temp.length = count;
	res.push_back(temp);

	return res;
}

void output(const vector<Segment>& result)
{
	// write your cool code here
	for(int i=0; i < result.size(); ++i){
		cout<<'('<<result[i].start<<","<<result[i].length<<')';
	}
	cout<<endl;

}

int main(int argc, char** argv)
{
	vector<vector<Segment>> segments;
	input(segments);
	auto result = merge(segments);
	output(result);

	system("pause");
	return 0;
}

*/













/*
int main(){
	string S;
	cin >> S;
	vector<int> v;
	int min = 9;
	for(int i=0; i< S.length(); i++){
		v.push_back(S[i] - '0');
	}
	sort(v.begin(), v.end());
	int i;
	for(i=0; i<v.size(); i++)
		if(v[i] != 0)	
			break;

	if(v[i]>1)
		cout<<1<<endl;
	else if(v[i] == 1 && (i+1 < v.size()) ){
		int res = v[i]*10 + v[i + 1] - 1;
		cout<<res<<endl;
	}
	system("pause");
	return 0;

}
*/

/*
int main(){
	string S;
	string T;
	cin >> S;
	cin >> T;
	int sum = 0;
	int num = 0;
	for(int i = 0; i < S.length() - T.length() + 1; ++i){
		num = 0;
		for(int j = 0; j < T.length(); ++j){
			if(S[i + j] != T[j])
				++num;
		}
		sum += num;
	}

	cout << sum;
	system("pause");
	return 0;
}
*/
/*
void func(int *a){
	static int j=-1;
	do{
		j+=1;
		a[j] = a[j]+a[j+1];
	}while(j<2);
}

int main(){
	int k,a[10]={1,2,3,4,5};
	for(k=1;k<3;k++) func(a);
	for(k=0;k<5;k++) printf("%d",a[k]);
	cout<<endl;
	system("pause");
	return  0;
}
*/
/*
int main(){
	string str;
	cin>>str;
	if(str.empty()){
		cout<<0<<endl;
		return 0;
	}
	int L_num = 0;
	if(str[0]=='L'){
		for(int i=0;i<str.size();i++){
			if(str[i]=='L')
				L_num++;
			else
				break;
		}
	}
	int R_num = 0;
	if(str[str.size()-1] == 'R'){
		for(int i=str.size()-1 ; i>=0 ; i--){
			if(str[i]=='R')
				R_num++;
			else
				break;
		}
	}
	if(L_num+R_num == str.size())
		cout<<str.size()<<endl;
	else
		cout<<L_num+R_num+1<<endl;

	system("pause");
	return 0;
}
*/
/*
//---------------
int WordCount(char S[],char a)  //统计单词个数函数(a是分隔符)
{
	int i=0,n=0;                   //循环变量和单词个数
	while(S[i]!='\0')              //逐个检测串里的字符
	{
		if(S[i]!=a&&S[i]!='\0')	 //如果碰到有效字符
		{
			n++;                  //单词个数加1
			while(S[i]!=a&&S[i]!='\0') i++;
		}//跳过后面一起的有效字符
		else i++;
	}			//如果没碰到有效字符检测下一个
	return n;
}		//函数返回单词个数

//---------------
int WordCount1(char S[])        //统计单词个数函数(不指定分隔符)
{
	int i=0,n=0;                   //循环变量和单词个数
	while(S[i]!='\0')              //逐个检测串里的字符
	{
		if((S[i]>='a'&&S[i]<='z')||(S[i]>='A'&&S[i]<='Z'))
	{n++;                  //单词个数加1
	while((S[i]>='a'&&S[i]<='z')||(S[i]>='A'&&S[i]<='Z'))
		i++;}				//跳过后面连在一起的所有有效字符
	else i++;}						//如果没碰到有效字符检测下一个
	return n;
}                      //函数返回单词个数
//---------------
int main()                              //主函数
{
	int n;                                 //单词数
	char chr[255];                         //英文句子字符串
	for(;;)                                //设置一个无穷循环
	{printf("请输入英文句子(END结束):");//输入提示
	gets(chr);                         //接收一个英文句子

	if(strcmp(chr,"END")==0) break;    //输入END退出循环结束函数 
	n=WordCount(chr,' ');              //获得单词数(空格分隔符)
	printf("以空隔分共有%d个单词\n",n);//输出单词个数
	n=WordCount1(chr);                 //获得单词数(不指定分隔符)
	printf("以字母分共有%d个单词\n\n",n);}//输出单词个数
	cout<<endl;                         //换行
	system("pause");                       //暂停屏幕查看结果
	return 0;
}                             //结束程序
*/
/*
#define MAX_PEOPLE 100  
#define MAX_WEIGHT 450  
#define MAX_WEIGHT_SUM MAX_PEOPLE*MAX_WEIGHT  
int weights[MAX_PEOPLE];    
  
bool** create2D(int x, int y) {  
    bool **array = new bool*[x];  
    for (int i = 0; i < x; ++i) {  
        array[i] = new bool[y];  
        memset(array[i], 0, sizeof(bool)*y);  
    }  
    return array;  
}  
  
void delete2D(int x, int y, bool **array) {  
    for (int i = 0; i < x; ++i) {  
        delete[] array[i];  
    }  
    delete[] array;  
}  
  
void memset2D(int x, int y, bool **array) {  
    for(int i = 0; i < x; ++i)  
        memset(array[i], 0, sizeof(bool)*y);  
}  
  
int main(void) {  
    int n, W, maxDiff, teamWeight, temp;  
    int minWeight = MAX_WEIGHT, maxWeight = -1;  

    cin >> n;  
    W = 0;  
    for(int i = 0; i < n; ++i) {  
        cin >> weights[i];  
        if(weights[i] < minWeight)  
            minWeight = weights[i];  
        if(weights[i] > maxWeight)  
            maxWeight = weights[i];  
  
        W += weights[i];  
    }  
    int maxW = maxWeight + (W>>1);  
    int maxn = n>>1;  
    int index = 0;  

    bool **table = create2D(maxn+1, maxW+1);   
    table[0][0] = true;  
    for(int k = 0; k < n; ++k) {   
        for(int j = min(k, maxn) ; j >= 1; --j) {   
            for(int i = maxW; i >=minWeight ; --i) {  
                if (table[j][i] == false) {  
                    index = i - weights[k];  
                    if (index < 0) break;   
                    table[j][i] = table[j-1][index];  
                } 
            } 
        } 
    }
  
    maxDiff = MAX_WEIGHT_SUM ;  
    teamWeight = 0;  
    for(int i = 0; i <= maxW; ++i) {  
        if (table[n/2][i]) {  
            temp = abs(abs(W - i) - i);  
            if (temp < maxDiff) {  
                maxDiff = temp;  
                teamWeight = i;  
            }  
        }  
    }  
    teamWeight = min(teamWeight, W-teamWeight);  
    //cout << teamWeight << " " << W - teamWeight << endl;  
	cout << abs(teamWeight - (W - teamWeight)) << endl;  
	cout << endl; 
	system("pause");
        return 0;  
} 
*/

/*
#define RADIX   10  //默认10进制
int main()
{
	int num = 0;
	int temp = 0;
	int i = 0;
	int preBit = 0;
	int sum = 0;
	int count = 0;
	int happyNumSum=0;
	cin>>num;

	for(i=1; i<=num; i++)
	{
		temp = i;

		while(1)
		{
			sum = 0;
			while(temp)
			{
				preBit = temp % RADIX;
				temp /= RADIX;
				sum += preBit * preBit;
			}
			if(sum == 1)
			{
				cout<<i<<" ";
				happyNumSum += i;
				break;
			}
			if(sum == 4)
			{
				count++;

				if(count>=3)
				{
					break;
					count = 0;
				}
			}
			temp = sum;
		}
	}
	cout<<endl;
	cout<<happyNumSum<<endl;
	system("pause");
	return 0;
}
*/