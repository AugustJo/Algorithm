#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

struct s1 {
	char ch, *ptr;
	union {
		short a, b;
		unsigned int c:2, d:1;
	};
	struct s1 *next;
};


void quickSort(int s[], int l, int r)  
{  
	if(l<r)  
	{        
		int low=l;                            //左边第一个，因为第一个已经用pivot保存了  
		int high=r;                           //右边  
		int pivot = s[l];                     //第一个，已被保存  
		while(low<high)                       //当左小于右,当相等的时候会跳出循环  
		{  
			while(low<high&&s[high]>= pivot)  // 从右向左找第一个小于x的数  
				high--;   
			if(low<high)                          
				s[low++] = s[high];  

			while(low<high&&s[low]<pivot)     // 从左向右找第一个大于等于x的数  
				low++;   
			if(low<high)    
				s[high--] = s[low];  
		}  
		s[low]=pivot;          
		quickSort(s, l, low - 1);             //low左边递归调用  
		quickSort(s, low + 1, r);             //low右边递归调用  
	}  
}


int main(void){
	
	int s[] = {5,7,4,8,3,7,2,6};
	quickSort(s, 0, 7);
	for(int i=0; i<8;i++)
		cout<<s[i]<<' ';
	cout<<endl;

	cout<< "sizeof struct s1:"<<sizeof(struct s1)<<endl;
	cout<< "sizeof struct s1*:"<<sizeof(struct s1*)<<endl;
	cout << "sizeof char *+ char :" << sizeof(char *) + sizeof(char)<<endl;

	vector<int> vec;
	cout << "输入整数，以任意字母结束：" << endl;
	int temp=0;
	while(cin >> temp)
		vec.push_back(temp);
	for(int i=0; i<vec.size();++i)
		cout << vec[i]<<' ';
	cout << endl;
	system("pause");
	return 0;
}