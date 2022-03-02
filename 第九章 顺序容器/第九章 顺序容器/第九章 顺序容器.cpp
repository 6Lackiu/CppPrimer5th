//练习9.4
/*
#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool myFind(vector<int>::const_iterator begin, vector<int>::const_iterator end, int n) {
	for (vector<int>::const_iterator it = begin; it != end; ++it) {
		if (*it == n) {
			return true;
		}
	}
	return false;
}

int main()
{
	vector<int> v = { 1,3,5,2,7,34,22,11,8,9 };
	if (myFind(v.begin(), v.end(), 11)) {
		cout << "找到" << endl;
	}
	else {
		cout << "没有找到" << endl;
	}


	system("pause");
	return 0;
}
*/




//练习9.5
/*
#include<iostream>
#include<vector>
#include<string>
#define NUM 5
using namespace std;

vector<int>::const_iterator myFind(vector<int>::const_iterator begin, vector<int>::const_iterator end, int n) {
	for (vector<int>::const_iterator it = begin; it != end; ++it) {
		if (*it == n) {
			return it;
		}
	}
	return end;
}

int main()
{
	vector<int> v = { 1,3,5,2,7,34,22,11,8,9 };
	vector<int>::const_iterator it = v.end();
	if (it != myFind(v.begin(), v.end(), NUM)) {
		cout << "元素下标为：" << myFind(v.begin(), v.end(), NUM) - v.begin() << endl;
	}
	else {
		cout << "没有找到元素" << endl;
	}


	system("pause");
	return 0;
}
*/



//练习9.13
/*
#include<iostream>
#include<vector>
#include<string>
#include<list>

using namespace std;

int main()
{
	list<int> List = { 1,3,5,7,9 };
	vector<int> Vector = { 2,4,6,8,10 };

	vector<double> myVector1(List.begin(), List.end());
	vector<double> myVector2(Vector.begin(), Vector.end());

	for (auto it = myVector1.cbegin(); it != myVector1.cend(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
	for (auto it = myVector2.cbegin(); it != myVector2.cend(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/




//练习9.14
/*
#include<iostream>
#include<vector>
#include<string>
#include<list>

using namespace std;

int main()
{
	list<const char*> myList{ "Hello" ,"world","!" };
	vector<string> v;

	v.assign(myList.begin(), myList.end());
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/




//练习9.15
/*
#include<iostream>
#include<vector>
#include<string>
#include<list>

using namespace std;

int main()
{
	vector<int> v{ 1,2,3,4,5,6,7 };
	vector<int> v1{ 1,2,3,4,5,6,7 };
	vector<int> v2{ 1,2,3,4,5 };
	vector<int> v3{ 1,2,3,4,5,6,8 };
	vector<int> v4{ 1,2,3,4,5,7,6 };

	cout << ((v == v1) ? "v与v1相等" : "v与v1不相等") << endl;
	cout << ((v == v2) ? "v与v2相等" : "v与v2不相等") << endl;
	cout << ((v == v3) ? "v与v3相等" : "v与v3不相等") << endl;
	cout << ((v == v4) ? "v与v4相等" : "v与v4不相等") << endl;

	system("pause");
	return 0;
}
*/




//练习9.16
/*
#include<iostream>
#include<vector>
#include<string>
#include<list>

using namespace std;

bool myEqual(list<int> myList, vector<int> myVector) {
	bool flag = true;
	if (myList.size() == myVector.size()) {
		auto lb = myList.cbegin(), le = myList.cend();
		auto vb = myVector.cbegin();
		for (; lb != le; ++lb, ++vb) {
			if (*lb != *vb) {
				flag = false;
			}
		}
	}
	else {
		flag = false;
	}

	return flag;
}

int main()
{
	vector<int> myVector{ 1,2,3,4,5,6,7 };
	list<int> myList1{ 1,2,3,4,5,6,7 };
	list<int> myList2{ 1,2,3,4,5 };
	list<int> myList3{ 1,2,3,4,5,6,8 };
	list<int> myList4{ 1,2,3,4,5,7,6 };

	cout << (myEqual(myList1, myVector) ? "list1和vector元素相等" : "list1和vector元素不等") << endl;
	cout << (myEqual(myList2, myVector) ? "list2和vector元素相等" : "list2和vector元素不等") << endl;
	cout << (myEqual(myList3, myVector) ? "list3和vector元素相等" : "list3和vector元素不等") << endl;
	cout << (myEqual(myList4, myVector) ? "list4和vector元素相等" : "list4和vector元素不等") << endl;

	system("pause");
	return 0;
}
*/




//练习9.18
/*
#include<iostream>
#include<vector>
#include<string>
#include<deque>

using namespace std;

int main()
{
	deque<string> myDeque;
	string s;
	while (cin >> s) {
		myDeque.push_back(s);
	}

	for (auto i : myDeque) {
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/



//练习9.19
/*
#include<iostream>
#include<vector>
#include<string>
#include<list>

using namespace std;

int main()
{
	string s;
	list<string> myList;

	while (cin >> s) {
		myList.push_back(s);
	}

	for (auto i : myList) {
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/




//练习9.20
/*
#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<deque>
using namespace std;

int main()
{
	deque<int> dq1, dq2;
	list<int> myList{ 1,2,3,4,5,6,7,8,9,10 };
	for (auto i : myList) {
		if (i % 2 == 0) {
			dq1.push_back(i);
		}
		else {
			dq2.push_back(i);
		}
	}

	for (auto i : dq1) {
		cout << i << ' ';
	}
	cout << endl << endl;
	for (auto i : dq2) {
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/




//练习9.24
/*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<int> iv;

	cout << iv.at(0) << endl;		//报出异常
	cout << iv[0] << endl;			//报错
	cout << iv.front() << endl;			//报错
	cout << *(iv.begin()) << endl;			//报错

	system("pause");
	return 0;
}
*/




//练习9.26
/*
#include<iostream>
#include<vector>
#include<string>
#include<list>

using namespace std;

int main()
{
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	vector<int> iv;
	list<int> il;

	iv.assign(ia, ia + 11);
	il.assign(ia, ia + 11);

	auto it1 = il.begin();
	while (it1 != il.end()) {
		if (*it1 % 2) {
			it1 = il.erase(it1);
		}
		else {
			++it1;
		}
	}

	auto it2 = iv.begin();
	while (it2 != iv.end()) {
		if ( !(*it2 % 2)) {
			it2 = iv.erase(it2);
		}
		else {
			++it2;
		}
	}

	for (auto i : iv) {
		cout << i << ' ';
	}
	cout << endl;
	for (auto i : il) {
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/




//练习9.27
/*
#include<iostream>
#include<vector>
#include<string>
#include<forward_list>

using namespace std;

int main()
{
	forward_list<int> ifl{ 1,2,3,4,5,6,7,8,9,10 };
	auto prev = ifl.before_begin();
	auto curr = ifl.begin();

	while (curr != ifl.end()) {
		if (*curr % 2) {
			curr = ifl.erase_after(prev);			//记住返回的是迭代器，要接收
			prev = curr;
			++curr;
		}
		else {
			++prev;
			++curr;
		}
	}

	for (auto i : ifl) {
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/





//练习9.28
/*
#include<iostream>
#include<vector>
#include<string>
#include<forward_list>

using namespace std;

void func(forward_list<string>& ifl, const string& s1, const string& s2) {
	auto prev = ifl.before_begin();
	auto curr = ifl.begin();
	bool isFind = false;

	while (curr != ifl.end()) {
		if (*curr == s1) {
			curr = ifl.insert_after(curr, s2);
			isFind = true;
		}
		prev = curr;
		++curr;
	}

	if (!isFind) {
		ifl.insert_after(prev, s2);			//此时curr指向尾后迭代器，prev指向尾后迭代器前一位置
	}
}

int main()
{
	forward_list<string> ifl{ "hello","world","yes" };
	string s1 = "ok", s2 = "no";
	func(ifl, s1, s2);
	for (auto i : ifl) {
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/





//练习9.31
//////   list
/*
#include<iostream>
#include<vector>
#include<string>
#include<list>

using namespace std;
int main()
{
	list<int> il{ 0,1,2,3,4,5,6,7,8,9 };
	auto it = il.begin();

	while (it != il.end()) {
		if (*it % 2) {
			it = il.insert(it, *it);
			++it, ++it;
		}
		else {
			it = il.erase(it);
		}
	}

	for (auto i : il) {
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/

///////   foward_list
/*
#include<iostream>
#include<vector>
#include<string>
#include<forward_list>

using namespace std;

int main()
{
	forward_list<int> ifl{ 0,1,2,3,4,5,6,7,8,9 };
	auto prev = ifl.before_begin();
	auto curr = ifl.begin();

	while (curr != ifl.end()) {
		if (*curr % 2) {
			curr = ifl.insert_after(curr, *curr);
			prev = curr;
			++curr;
		}
		else {
			curr = ifl.erase_after(prev);
		}
	}

	for (auto i : ifl) {
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/




//练习9.38
 /*
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<int> v;
	for (int i = v.size() , j = v.capacity(); i <= j ; ++i) {
		v.push_back(1);
	}
	cout << "size = " << v.size() << "   capacity = " << v.capacity() << endl;

	for (int i = v.size(), j = v.capacity(); i <= j; ++i) {
		v.push_back(1);
	}
	cout << "size = " << v.size() << "   capacity = " << v.capacity() << endl;

	for (int i = v.size(), j = v.capacity(); i <= j; ++i) {
		v.push_back(1);
	}
	cout << "size = " << v.size() << "   capacity = " << v.capacity() << endl;

	for (int i = v.size(), j = v.capacity(); i <= j; ++i) {
		v.push_back(1);
	}
	cout << "size = " << v.size() << "   capacity = " << v.capacity() << endl;

	for (int i = v.size(), j = v.capacity(); i <= j; ++i) {
		v.push_back(1);
	}
	cout << "size = " << v.size() << "   capacity = " << v.capacity() << endl;

	for (int i = v.size(), j = v.capacity(); i <= j; ++i) {
		v.push_back(1);
	}
	cout << "size = " << v.size() << "   capacity = " << v.capacity() << endl;

	for (int i = v.size(), j = v.capacity(); i <= j; ++i) {
		v.push_back(1);
	}
	cout << "size = " << v.size() << "   capacity = " << v.capacity() << endl;

	for (int i = v.size(), j = v.capacity(); i <= j; ++i) {
		v.push_back(1);
	}
	cout << "size = " << v.size() << "   capacity = " << v.capacity() << endl;

	system("pause");
	return 0;
}
*/




//练习9.41
/*
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<char> vc = { 'H','e','l','l','o' };
	string s(vc.data(), vc.size());
	cout << s << endl;

	system("pause");
	return 0;
}
*/





//练习9.42
/*
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void mystring_put(string& s) {
	s.reserve(100);
	char c;
	while (cin >> c) {
		s.push_back(c);
	}
}

int main()
{
	string s;
	mystring_put(s);
	cout << s << endl;

	system("pause");
	return 0;
}
*/




//练习9.44
/*
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void func(string& s, const string& oldVal, const string& newVal) {
	int p = 0;
	while ((p = s.find(oldVal, p)) != s.npos) {
		s.replace(p, oldVal.size(), newVal);
		p += newVal.size();
	}
}

int main()
{
	string s = "tho thru tho";
	func(s, "tho", "though");
	cout << s << endl;

	func(s, "thru", "through");
	cout << s << endl;

	func(s, "through", "*");
	cout << s << endl;

	system("pause");
	return 0;
}
*/




//练习9.45
/*
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void func(string& s, const string& pre, const string& suf) {
	s.insert(s.begin(), ' ');
	s.insert(s.begin(), pre.begin(), pre.end());
	s.append(" ");
	//s.append(suf.begin(), suf.end());
	s.append(suf);
}

int main()
{
	string s = "Liu";
	func(s, "Mr.", "Jr.");
	cout << s << endl;

	system("pause");
	return 0;
}
*/




//练习9.46
/*
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void func(string& s, const string& pre, const string& suf) {
	s.insert(0, " ");
	s.insert(0, pre);
	s.insert(s.size(), " ");
	s.insert(s.size(), suf);
}

int main()
{
	string s = "Liu";
	func(s, "Mr.", "Jr.");
	cout << s << endl;

	s = "Mary";
	func(s, "Mrs.", "Ⅱ");
	cout << s << endl;

	system("pause");
	return 0;
}
*/




//练习9.47
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void myFind1(string& s, const string& tar) {
	int pos = 0;
	while ((pos = s.find_first_of(tar, pos)) != s.npos) {
		cout << "pos : " << pos << ", char : " << s[pos] << endl;
		++pos;
	}
}

void myFind2(string& s, const string& tar) {
	int pos = 0;
	while ((pos = s.find_first_not_of(tar, pos)) != s.npos) {
		cout << "pos : " << pos << ", char : " << s[pos] << endl;
		++pos;
	}
}

int main()
{
	string s = "ab2c3d7R4E6";
	cout << "*** 版本一 ***" << endl;
	cout << "查找所有数字：" << endl;
	myFind1(s, "0123456789");
	cout << endl << "查找所有字母：" << endl;
	myFind1(s, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");


	cout << endl << endl << "*** 版本二 ***" << endl;
	cout << "查找所有数字：" << endl;
	myFind2(s, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	cout << endl << "查找所有字母：" << endl;
	myFind2(s, "0123456789");

	system("pause");
	return 0;
}
*/



//练习9.49
//本代码修改了题意，写的答案与题目要求不符
//下述代码是寻找某个字符串中不含出头字符的最长部分字符数
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void find_longest_word(string& s) {
	int cnt = 0, max = 0;
	string str = "bdfghjklpqty";
	for (auto c : s) {
		string::size_type idx;
		if (str.find(c) == str.npos) {
			++cnt;
			if (cnt > max) {
				max = cnt;
			}
		}
		else {
			cnt = 0;
		}
	}
	cout << max << endl;
}

int main()
{
	string s = "gahremq";
	find_longest_word(s);

	system("pause");
	return 0;
}
*/



//练习9.50
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	vector<string> vs = { "10","+4","-9" };
	int sum = 0;

	for (auto it = vs.begin(); it != vs.end(); ++it) {
		sum += stoi(*it);
	}
	cout << sum << endl;

	vector<string> vs2 = { "1.5","+2.5","-3.5" };
	double sum2 = 0;
	for (auto it2 = vs2.begin(); it2 != vs2.end(); ++it2) {
		sum2 += stof(*it2);
	}
	cout << sum2 << endl;

	system("pause");
	return 0;
}
*/



//练习9.51
//参考答案
/*
#include<iostream>
#include<string>
#include "date.h"

using namespace std;

int main()
{
	string dates[] = { "Jan 1,2014","February 1 2014","3/1/2014",
		//  "Jcn 1,2014",
		//   "Janvary 1,2014",
		//   "Jan 32,2014",
		//   "Jan 1/2014",
			  "3 1 2014 " };

	try {
		for (auto ds : dates) {
			date d1(ds);
			cout << d1;
		}
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
	}

	system("pause");
	return 0;
}
*/



//练习9.52
//参考答案
/*
#include<iostream>
#include<string>
#include<deque>
#include<stack>
#include<stdexcept>

using namespace std;

//表示栈中对象的不同类型
enum obj_type {
	LP, RP, ADD, SUB, VAL
};
struct obj {
	obj(obj_type type, double val = 0) {
		t = type;
		v = val;
	}
	obj_type t;
	double v;
};

inline void  skipws(string& exp, size_t& p) {
	p = exp.find_first_not_of(" ", p);
}

inline void new_val(stack<obj>& so, double v) {
	if (so.empty() || so.top().t == LP) {					//空栈或左括号
		so.push(obj(VAL, v));
		//cout << "push " << v << endl;
	}
	else if (so.top().t == ADD || so.top().t == SUB) {
		//之前是运算符
		obj_type type = so.top().t;
		so.pop();

		//if (type == ADD)
		//		cout << "pop +" << endl;
		//else
		//		cout << "pop - " << endl;

		//cout << "pop " << so.top().v << endl;

		//执行加减法
		if (type == ADD)
			v += so.top().v;
		else
			v -= so.top().v;
		so.pop();
		so.push(obj(VAL, v));					//运算结果压栈
		//cout << "push " << v << endl;
	}
	else
		throw invalid_argument("缺少运算符");
}

int main()
{
	stack<obj> so;
	string exp;
	size_t p = 0, q;
	double v;

	cout << "请输入表达式：";
	getline(cin, exp);

	while (p < exp.size()) {
		skipws(exp, p);
		if (exp[p] == '(') {
			so.push(obj(LP));
			++p;
			//cout << "push LP" << endl;
		}
		else if (exp[p] == '+' || exp[p] == '-') {
			//新运算符
			if (so.empty() || so.top().t != VAL)
				//空栈或之前不是运算数
				throw invalid_argument("缺少运算数");
			if (exp[p] == '+')					//运算符压栈
				so.push(obj(ADD));
			else
				so.push(obj(SUB));
			++p;
			//cout << "push " << exp[p - 1] << endl;
		}
		else if (exp[p] == ')') {					//右括号
			++p;
			if (so.empty())							//之前无配对的左括号
				throw invalid_argument("未匹配右括号");

			if (so.top().t == LP)					//一对括号之间无内容
				throw invalid_argument("空括号");

			if (so.top().t == VAL) {				//正确：括号内运算结果
				v = so.top().v;
				so.pop();
				//cout << "pop " << v << endl;

				if (so.empty() || so.top().t != LP)
					throw invalid_argument("未匹配右括号");

				so.pop();
				//cout << "pop LP" << endl;
				new_val(so, v);					//与新运算数逻辑一致
			}
			else										//栈顶必定是运算符
				throw invalid_argument("缺少运算数");
		}
		else {										//应该是运算数
			v = stod(exp.substr(p), &q);
			p += q;
			new_val(so, v);
		}
	}

	if (so.size() != 1 || so.top().t != VAL)
		throw invalid_argument("非法表达式");

	cout << so.top().v << endl;

	system("pause");
	return 0;
}
*/