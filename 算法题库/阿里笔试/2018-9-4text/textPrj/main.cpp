#include<iostream>
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

