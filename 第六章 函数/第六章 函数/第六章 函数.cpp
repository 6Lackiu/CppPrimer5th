//练习6.7
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void myCount() {
	static int cnt = 0;
	cout << "cnt=" << cnt << endl;
	cnt++;
}

int main() {
	for (int i = 0; i < 5; ++i) {
		myCount();
	}
	system("pause");
	return 0;
}
*/



//练习6.1和练习6.12
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void ptrswap(int* a, int* b) {		//通过解引用改变指针所指内容
	int temp = *a;
	*a = *b;
	*b = temp;
}

void refswap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {
	int x = 1, y = 2;
	int* p = &x, * q = &y;
	ptrswap(p, q);
	cout << x << "   " << y << endl;

	int m = 10, n = 20;
	refswap(m, n);
	cout << m << "   " << n << endl;

	system("pause");
	return 0;
}
*/



//练习6.17
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool hasUpper(const string& s) {
	bool flag = false;
	for (auto& c : s) {
		if (isupper(c)) {
			flag = true;
		}
	}
	return flag;
}

void mylower(string& s) {
	for (auto& c : s) {
		c = tolower(c);
	}
}

int main() {
	string s;
	cout << "输入一个字符串：" << endl;
	cin >> s;
	if (hasUpper(s)) {
		mylower(s);
		cout << s << endl;
	}
	else {
		cout << "字符串都是小写字母，无需转换" << endl;
	}

	system("pause");
	return 0;
}
*/



//练习6.21
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int myCompare(const int x, const int* y) {
	return (x > *y) ? x : *y;
}

int main() {
	int a = 30, b = 20;
	int* p = &b;
	cout << myCompare(a, p) << endl;

	system("pause");
	return 0;
}
*/




//练习6.22
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void mySwap01(int* p, int* q) {		//既不交换地址，也不交换内容
	int* temp = p;
	p = q;
	q = temp;
}

void mySwap02(int* p, int* q) {		//交换指针内容
	int temp = *p;
	*p = *q;
	*q = temp;
}

//若想要只交换指针指向的地址，函数应该写为void mySwap03(int*& p, int*& q);

int main() {
	int a1 = 10, b1 = 20;
	int* p1 = &a1, * q1 = &b1;
	mySwap01(p1, q1);
	cout << "a1=" << a1 << "   b1=" << b1 << endl;

	int a2 = 10, b2 = 20;
	int* p2 = &a2, * q2 = &b2;
	mySwap02(p2, q2);
	cout << "a2=" << a2 << "   b2=" << b2 << endl;

	system("pause");
	return 0;
}
*/



//练习6.23
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void myPrint1(const int* p) {
	cout << *p++ << endl;
}

void myPrint2(const int* p, const int sz) {
	int i = 0;
	while (i != sz) {
		cout << *p++ << endl;
		++i;
	}
}

//自认为更好一点
void myPrint3(const int* beg, const int* end) {
	while (beg != end) {
		cout << *beg++ << endl;
	}
}

int main() {
	int i = 0, j[2] = { 0,1 };
	myPrint1(&i);
	myPrint1(j);
	cout << "------------" << endl;
	myPrint2(&i, 1);
	myPrint2(j, sizeof(j) / sizeof(int));
	cout << "------------" << endl;
	myPrint3(begin(j), end(j));

	system("pause");
	return 0;
}
*/



//练习6.25
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int argc,char* argv[]) {
	string s;
	for (int i = 0; i != argc; ++i) {
		s += argv[i];
	}
	cout << s << endl;

	system("pause");
	return 0;
}
*/




//练习6.32
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int& get(int* array, int index) {
	return array[index];
}

int main() {
	int ia[10];
	for (int i = 0; i != 10; ++i) {
		get(ia, i) = i;
		cout << get(ia, i) << endl;
	}
	system("pause");
	return 0;
}
*/




//练习6.33
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void myPrint(vector<int> v, int index) {
	int sz=v.size();
	if (!v.empty() && index<sz) {
		cout << v[index] << " ";
		myPrint(v, index + 1);
	}
}

int main() {
	vector<int> v = { 1,3,5,6,7,8 };
	myPrint(v, 0);

	system("pause");
	return 0;
}
*/



//练习6.36 练习6.37
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

string (&func1 (string s))[10];	//练习6.36

//练习6.37
//类型别名
typedef string arr[10];
arr& func2();
//尾置返回类型
auto func3()->string(&)[10];
//decltype关键字
string s[10];
decltype(s)& func();

int main() {

	system("pause");
	return 0;
}
*/




//练习6.42
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

string make_plural(size_t ctr, const string& word, const string& ending = "s") {
	return (ctr > 1) ? word + ending : word;
}

int main() {
	cout << "success单数：" << make_plural(1, "success", "es") << endl;
	cout << "success复数：" << make_plural(2, "success", "es") << endl;
	cout << "failure单数：" << make_plural(1, "failure") << endl;
	cout << "failure复数：" << make_plural(2, "failure") << endl;

	system("pause");
	return 0;
}
*/




//练习6.44
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//内联函数
inline bool isShorter(const string& s1, const string& s2) {
	return s1.size() < s2.size();
}

int main() {
	string s1 = "Hello", s2 = "Hi";
	bool flag = isShorter(s1, s2);
	if (flag) {
		cout << "s1比s2短" << endl;
	}
	else {
		cout << "s2比s1短" << endl;
	}

	system("pause");
	return 0;
}
*/



//练习6.54  练习6.55  练习6.56
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int func(int, int);

inline int myAdd(int a, int b) {
	return a + b;
}
inline int mySub(int a, int b) {
	return a - b;
}
inline int myMul(int a, int b) {
	return a * b;
}
inline int myDiv(int a, int b) {
	return a / b;
}

inline void myCompute(int a, int b, int (*p)(int, int)) {
	cout << (*p)(a, b) << endl;
}

int main() {
	vector<decltype(func)*> v = { myAdd,mySub,myMul,myDiv };     //decltype(func)* 指向func的指针类型

	for (auto p : v) {
		myCompute(10, 5, p);
	}

	system("pause");
	return 0;
}
*/