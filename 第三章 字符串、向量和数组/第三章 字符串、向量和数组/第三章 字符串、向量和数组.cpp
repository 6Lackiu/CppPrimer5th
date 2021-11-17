//练习3.2
/*
#include<iostream>
#include<string>
using namespace std;

void test01()
{
	cout << "1.请输入一行话：";
	string s;
	getline(cin, s);
	cout << s << endl;
}
void test02()
{
	cout << "2.请输入一行话：";
	string s;
	cin >> s;
	cout << s << endl;
}
int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
*/


//练习3.4
/*
#include<iostream>
#include<string>
using namespace std;

void isequal(string& s1, string& s2)
{
	if (s1 != s2)
	{
		cout << ((s1 > s2) ? s1 : s2) << endl;
	}
	else
	{
		cout << "两个字符串相等" << endl;
	}
}

void LenIsEqual(string& s1, string& s2)
{
	if (s1.size() != s2.size())
	{
		cout << ((s1.size() > s2.size()) ? s1 : s2) << endl;
	}
	else
	{
		cout << "两个字符串长度相等" << endl;
	}
}

int main()
{
	string s1, s2;
	cout << "请输入第一个字符串：";
	cin >> s1;
	cout << "请输入第二个字符串：";
	cin >> s2;

	isequal(s1, s2);
	LenIsEqual(s1, s2);

	system("pause");
	return 0;
}
*/


//练习3.4
/*
#include<iostream>
#include<string>
using namespace std;

int main()
{

	system("pause");
	return 0;
}
*/


//练习3.5
/*
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string mystring, sumstring;

	while (getline(cin, mystring))
	{
		sumstring += mystring+" ";
		cout << sumstring << endl;
	}

	system("pause");
	return 0;
}
*/


//练习3.10
/*
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1;
	cout << "请输入一个带标点的字符串：" << endl;
	cin >> s1;
	for (auto& c : s1)
	{
		if (!ispunct(c))
		{
			cout << c;
		}
	}
	cout << endl;

	system("pause");
	return 0;
}
*/



//练习3.14
/*
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void test01()
{
	vector<int> v;
	int num;
	while (cin >> num)
	{
		v.push_back(num);
	}
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}
void test02()
{
	vector<string> v;
	string s;;
	while (cin >> s)
	{
		v.push_back(s);
	}
	for (auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
*/


//练习3.17
/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<string> v;
	string s;
	while (cin >> s)
	{
		v.push_back(s);
	}
	for (int i=0;i<v.size();++i)
	{
		for (int j=0;j<v[i].length();++j)
		{
			v[i][j] = toupper(v[i][j]);
		}
	}
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << endl;
	}

	system("pause");
	return 0;
}
*/


//练习3.20
/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void test01()
{
	vector<int> v;
	int num;
	while (cin >> num)
	{
		v.push_back(num);
	}
	for (int i = 0; i < v.size()-1; i+=2)
	{
		cout << v[i] + v[i + 1] << ' ';
	}
	cout << endl;
}

void test02()
{
	vector<int> v;
	int num;
	while (cin >> num)
	{
		v.push_back(num);
	}
	for (int i = 0; i < v.size()/2; i++)
	{
		cout << v[i] + v[v.size()-1-i] << ' ';
	}
	cout << endl;
}

int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
*/



//练习3.23
/*
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v(10, 3);
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		*it = (*it) * 2;
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
*/



//练习3.24
/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	vector<int> v(10);
	for (int i = 0; i < 10; i++)
	{
		cin >> v[i];
	}
	for (auto itbeg = v.begin(),itend=v.end();itbeg!=itend;itbeg++)
	{
		itend--;
		cout << (*itbeg) + (*itend) << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/



//练习3.25
/*
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<unsigned> scores(11, 0);
	unsigned grade;
	while (cin >> grade && grade != 'n')
	{
		if (grade <= 100)
		{
			auto it = scores.begin();
			it += grade / 10;
			(*it)++;
		}
	}
	for (auto i : scores)
	{
		cout << i << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}
*/



//练习3.32
/*
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int> v2 = v1;
	for (int i = 0; i < 10; i++)
	{
		cout << v1[i] << ' ';
	}
	cout << endl << "---------------------" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << v2[i] << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}
*/




//练习3.35
/*
#include<iostream>
using namespace std;

int main()
{
	int a[5] = { 2,4,7,32,6 };
	for (int* p = begin(a); p != end(a); ++p)
	{
		*p = 0;
	}
	for (int i = 0; i < 5; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}
*/




//练习3.36
/*
#include<iostream>
#include<vector>
using namespace std;

void test01()
{
	int a[5] = { 3,2,4,6,1 }, b[5] = { 3,2,4,7,1 };
	bool flag = 1;
	for (int i = 0; i < 5; ++i)
	{
		if (a[i] != b[i])
		{
			flag = 0;
		}
	}
	if (flag)
	{
		cout << "两个数组相等" << endl;
	}
	else
	{
		cout << "两个数组不相等" << endl;
	}
}

void test02()
{
	vector<int> v1 = { 1,3,3,6,8 };
	vector<int> v2 = { 1,3,4,6,8 };
	bool flag = 1;
	for (int i = 0; i < 5; ++i)
	{
		if (v1[i] != v2[i])
		{
			flag = 0;
		}
	}
	if (flag)
	{
		cout << "两个vector对象相等" << endl;
	}
	else
	{
		cout << "两个vector对象不相等" << endl;
	}
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
*/



//练习3.43  多做多看！！！！！！
/*
#include<iostream>
using namespace std;

//版本1
void test01()
{
	int a[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	for (int (&row)[4] : a)
	{
		for (int col : row)
		{
			cout << col << '\t';
		}
		cout << endl;
	}
}

//版本2
void test02()
{
	int a[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 4; ++col)
		{
			cout << a[row][col] << '\t';
		}
		cout << endl;
	}
}

//版本3
void test03()
{
	int a[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	for (int(*p)[4] = a; p != a + 3; ++p)
	{
		for (int* q = *p; q != *p + 4; ++q)
		{
			cout << *q << '\t';
		}
		cout << endl;
	}
}

int main()
{
	test01();
	cout << "---------------------------" << endl;
	test02();
	cout << "---------------------------" << endl;
	test03();

	system("pause");
	return 0;
}
*/



//练习3.44
/*
#include<iostream>
using namespace std;
using int_array = int[4];

//版本1
void test01()
{
	int a[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	for (int_array &row : a)
	{
		for (int col : row)
		{
			cout << col << '\t';
		}
		cout << endl;
	}
}

//版本2
void test02()
{
	int a[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 4; ++col)
		{
			cout << a[row][col] << '\t';
		}
		cout << endl;
	}
}

//版本3
void test03()
{
	int a[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	for (int_array *p = a; p != a + 3; ++p)
	{
		for (int* q = *p; q != *p + 4; ++q)
		{
			cout << *q << '\t';
		}
		cout << endl;
	}
}

int main()
{
	test01();
	cout << "---------------------------" << endl;
	test02();
	cout << "---------------------------" << endl;
	test03();

	system("pause");
	return 0;
}
*/



//练习3.45
/*
#include<iostream>
using namespace std;

//版本1
void test01()
{
	int a[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	for (auto &row : a)
	{
		for (auto col : row)
		{
			cout << col << '\t';
		}
		cout << endl;
	}
}

//版本2
void test02()
{
	int a[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	for (auto row = 0; row < 3; ++row)
	{
		for (auto col = 0; col < 4; ++col)
		{
			cout << a[row][col] << '\t';
		}
		cout << endl;
	}
}

//版本3
void test03()
{
	int a[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	for (auto p= a; p != a + 3; ++p)
	{
		for (auto q = *p; q != *p + 4; ++q)
		{
			cout << *q << '\t';
		}
		cout << endl;
	}
}

int main()
{
	test01();
	cout << "---------------------------" << endl;
	test02();
	cout << "---------------------------" << endl;
	test03();

	system("pause");
	return 0;
}
*/