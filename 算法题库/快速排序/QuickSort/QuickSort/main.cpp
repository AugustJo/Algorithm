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
		int low=l;                            //��ߵ�һ������Ϊ��һ���Ѿ���pivot������  
		int high=r;                           //�ұ�  
		int pivot = s[l];                     //��һ�����ѱ�����  
		while(low<high)                       //����С����,����ȵ�ʱ�������ѭ��  
		{  
			while(low<high&&s[high]>= pivot)  // ���������ҵ�һ��С��x����  
				high--;   
			if(low<high)                          
				s[low++] = s[high];  

			while(low<high&&s[low]<pivot)     // ���������ҵ�һ�����ڵ���x����  
				low++;   
			if(low<high)    
				s[high--] = s[low];  
		}  
		s[low]=pivot;          
		quickSort(s, l, low - 1);             //low��ߵݹ����  
		quickSort(s, low + 1, r);             //low�ұߵݹ����  
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
	cout << "������������������ĸ������" << endl;
	int temp=0;
	while(cin >> temp)
		vec.push_back(temp);
	for(int i=0; i<vec.size();++i)
		cout << vec[i]<<' ';
	cout << endl;
	system("pause");
	return 0;
}