#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>

using namespace std;

string sum(string, string, string, string);
string sub(string, string, string, string);

bool main()
{
	string num1, num2;
	cout << "Input num1 , num2:" << endl;
	cin >> num1 >> num2;
	string num11, num12, num21, num22;
	//输入检查
	//是否是小数的标志
	bool num1Flag = false, num2Flag = false;
	for (auto c : num1)
	{
		//由数字或者数字加一个.组成
		if (!isdigit(c) || num1.empty())
		{
			if (c == '.' && !num1Flag)
			{
				num1Flag = true;
			}
			else
			{
				cout << "num1: Please input correct form!!!" << endl;
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
				cout << "num2: Please input correct form!!!" << endl;
				return 0;
			}
		}
	}

	//字符串分割{整数部分和小数部分)
	if (num1Flag)//如果是小数
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
		//用于.XXX或XXX.型输入的控制
		if (num11.empty())
			num11 += '0';
		if (num12.empty())
			num12 += '0';
	}
	else//如果是整数
	{
		num11 = num1;
		num12 += '0';
	}
	if (num2Flag)//如果是小数
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
		//用于.XXX或XXX.型输入的控制
		if (num21.empty())
			num21 += '0';
		if (num22.empty())
			num22 += '0';
	}
	else//如果是整数str
	{
		num21 = num2;
		num22 += '0';
	}

	cout << "The Sum result = " << sum(num11, num12, num21, num22) << endl;
	cout << "The Sub result = " << sub(num11, num12, num21, num22) << endl;
	system("pause");
}


//加法  较长的整数部分 较长的小数部分 较短的整数部分 较短的小数部分
string sum(string strLong1, string strLong2, string strShort1, string strShort2)
{
	//小数部分计算
	if (strLong2.size() < strShort2.size())
		swap(strLong2, strShort2);

	//补0
	for (int i = strShort2.size(); i < strLong2.size(); ++i)
		strShort2 += '0';
	//反转字符串
	reverse(strLong2.begin(), strLong2.end());
	reverse(strShort2.begin(), strShort2.end());
	//小数部分进行加法计算
	string strRes2(strLong2.size(), '0');
	int carry = 0;//进位
	for (int i = 0; i != strLong2.size(); ++i)
	{
		int a = strShort2[i] - '0', b = strLong2[i] - '0';
		a = a + b + carry;
		carry = a / 10;
		strRes2[i] = (a % 10) + '0';
	}
	//反转回来
	reverse(strRes2.begin(), strRes2.end());


	//整数部分计算
	if (strLong1.size() < strShort1.size())
		swap(strLong1, strShort1);

	//反转字符串
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
	//反转回来
	reverse(strRes1.begin(), strRes1.end());


	//合并整数部分和小数部分
	string strRes = strRes1 + '.' + strRes2;
	return strRes;
}

//减法 被减数的整数部分 被减数的小数部分 减数的整数部分 减数的小数部分
string sub(string strBjs1, string strBjs2, string strJs1, string strJs2)
{
	//小数部分进行减法计算
	int cntTemp = strBjs2.size() - strJs2.size();
	//补0
	if (cntTemp <= 0)
	{
		for (int i = cntTemp; i != 0; ++i)
		{
			strBjs2 += '0';
		}
	}
	else
	{
		for (int i = cntTemp; i != 0; --i)
		{
			strJs2 += '0';
		}
	}

	//反转字符串
	reverse(strBjs2.begin(), strBjs2.end());
	reverse(strJs2.begin(), strJs2.end());
	string strRes2(strBjs2.size(), '0');
	int carry = 0;//进位
	for (int i = 0; i != strBjs2.size(); ++i)
	{
		int a = strBjs2[i] - '0', b = strJs2[i] - '0';
		a = a - b - carry;
		if (a >= 0)
		{
			carry = 0;
			strRes2[i] = a + '0';
		}
		else
		{
			carry = 1;
			strRes2[i] = a + 10 + '0';
		}
	}
	//反转回来
	reverse(strRes2.begin(), strRes2.end());

	//整数部分进行减法计算
	//反转字符串
	reverse(strBjs1.begin(), strBjs1.end());
	reverse(strJs1.begin(), strJs1.end());
	string strRes1(strBjs1.size(), '0');
	for (int i = 0; i != strJs1.size(); ++i)
	{
		int a = strBjs1[i] - '0', b = strJs1[i] - '0';
		a = a - b - carry;
		if (a >= 0)
		{
			carry = 0;
			strRes1[i] = a + '0';
		}
		else
		{
			carry = 1;
			strRes1[i] = a + 10 + '0';
		}
	}
	for (int i = strJs1.size(); i != strBjs1.size(); ++i)
	{
		int a = strBjs1[i] - '0';
		a = a - carry;
		if (a >= 0)
		{
			carry = 0;
			strRes1[i] = a + '0';
		}
		else
		{
			carry = 1;
			strRes1[i] = a + 10 + '0';
		}
	}
	if (carry)//此时除数比被除数大，结果为负数
	{
		return "*";
	}
	//反转回来
	reverse(strRes1.begin(), strRes1.end());

	//清楚冗余0
	string strTemp;
	cntTemp = 0;
	for (int i = 0; strRes1[i] == '0'; ++i)++cntTemp;
	for (int i = cntTemp; i != strRes1.size(); ++i)
		strTemp += strRes1[i];
	strRes1 = strTemp;
	//合并整数部分和小数部分
	string strRes = strRes1 + '.' + strRes2;
	//system("pause");
	return strRes;
}
