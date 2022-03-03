//练习10.1
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
	vector<int> vi = { 1,2,3,3,4,5,9,9,12,4,4,6,7 };
	int cnt = 0;
	cnt = count(vi.cbegin(), vi.cend(), 3);
	cout << cnt << endl;

	system("pause");
	return 0;
}
*/



//练习10.2
/*
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
	list<string> ls = { "hello","yes","no","yes","ok","bye" };
	cout << count(ls.cbegin(), ls.cend(), "yes") << endl;

	system("pause");
	return 0;
}
*/




//练习10.3
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
	vector<int> vi = { 1,10,20,100 };
	cout << accumulate(vi.cbegin(), vi.cend(), 5) << endl;

	system("pause");
	return 0;
}
*/




//练习10.6
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
	vector<int> vi;
	int num;
	while (cin>>num) {
		vi.push_back(num);
	}
	cout << "更改前：" << endl;
	for (auto i : vi) {
		cout << i << ' ';
	}
	cout << endl << "更改后：" << endl;

	fill_n(vi.begin(), vi.size(), 0);
	for (auto i = vi.begin(); i != vi.end();++i) {
		cout << *i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/



//练习10.9
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

void printWord(vector<string>& words) {
	for (auto word : words) {
		cout << word << ' ';
	}
	cout << endl;
}

void elimDups(vector<string>& words) {
	cout << "初始words：" << endl;
	printWord(words);

	sort(words.begin(), words.end());
	cout << "排序后words：" << endl;
	printWord(words);

	auto end_unique = unique(words.begin(), words.end());
	cout << "调用unique后words：" << endl;
	printWord(words);

	words.erase(end_unique, words.end());
	cout << "去重后words：" << endl;
	printWord(words);
}

int main() {
	string word;
	vector<string> words;
	cout << "请输入一些单词：" << endl;
	
	while (cin >> word) {
		words.push_back(word);
	}
	elimDups(words);

	system("pause");
	return 0;
}
*/



//练习10.11
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

inline void printWord(vector<string>& words) {
	for (auto word : words) {
		cout << word << ' ';
	}
	cout << endl << endl;
}

void elimDups(vector<string>& words) {
	cout << "初始words：" << endl;
	printWord(words);

	sort(words.begin(), words.end());
	cout << "排序后words：" << endl;
	printWord(words);

	auto end_unique = unique(words.begin(), words.end());
	cout << "调用unique后words：" << endl;
	printWord(words);

	words.erase(end_unique, words.end());
	cout << "去重后words：" << endl;
	printWord(words);
}

bool isShorter(const string& s1, const string& s2) {
	return s1.size() < s2.size();
}

int main() {
	string word;
	vector<string> words;
	cout << "请输入一些单词：" << endl;

	while (cin >> word) {
		words.push_back(word);
	}

	elimDups(words);

	stable_sort(words.begin(), words.end(), isShorter);
	cout<<"stable_sort后："<<endl;
	printWord(words);

	system("pause");
	return 0;
}
*/




//练习10.13
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

bool FivePlus(const string& s) {
	return s.size() > 5 ? true : false;
}

void myPrint(vector<string>::iterator beg, vector<string>::iterator end) {
	for (auto it = beg; it != end; ++it) {
		cout << *it << ' ';
	}
	cout << endl;
}

int main() {
	string word;
	vector<string> words;
	cout << "请输入一些单词：" << endl;
	while (cin >> word) {
		words.push_back(word);
	}
	cout << "调用partition前：" << endl;
	myPrint(words.begin(), words.end());

	auto it = partition(words.begin(), words.end(), FivePlus);
	cout << endl << "调用partition后：" << endl;
	myPrint(words.begin(), words.end());

	system("pause");
	return 0;
}
*/




//练习10.14
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
	auto sum = [](int a, int b) {
		return a + b;
	};
	cout << sum(3, 5) << endl;

	system("pause");
	return 0;
}
*/




//练习10.15
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

void add(int num) {
	auto sum = [num](int a) {
		return num + a;
	};

	cout << sum(6) << endl;					// a = 6
}

int main() {
	add(10);					// num = 10
	add(15);					// num = 15

	system("pause");
	return 0;
}
*/





//练习10.16	考察全面，建议多练
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

string make_plural(size_t n, const string& s, const string& ending) {
	return n > 1 ? s + ending : s;
}

void elimDups(vector<string>& words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

inline void myPrint(vector<string>& words) {
	for (auto it = words.begin(); it != words.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
}

void biggies(vector<string>& words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.size() < b.size(); });
	auto wc = find_if(words.begin(), words.end(), [sz](const string& a) {return a.size() >= sz; });

	auto cnt = words.end() - wc;
	cout << cnt << " " << make_plural(cnt, "word", "s") << " of length " << sz << " or longer" << endl;

	for_each(wc, words.end(), [](const string& s) {cout << s << " "; });
	cout << endl;
}

int main() {
	string word;
	vector<string> words;
	cout << "请输入一些单词：" << endl;
	while (cin >> word) {
		words.push_back(word);
	}

	biggies(words, 4);

	system("pause");
	return 0;
}
*/





//练习10.18
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

string make_plural(size_t n, const string& s, const string& ending) {
	return n > 1 ? s + ending : s;
}

void elimDups(vector<string>& words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

inline void myPrint(vector<string>& words) {
	for (auto it = words.begin(); it != words.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
}

inline bool LessFour(const string& s) {
	return s.size() < 4 ? true : false;
}


void biggies(vector<string>& words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.size() < b.size(); });

	//两种写法均可
	auto wc = partition(words.begin(), words.end(), LessFour);
	//auto wc = partition(words.begin(), words.end(), [sz](const string& a) {return a.size() < sz; });

	auto cnt = words.end() - wc;
	cout << cnt << " " << make_plural(cnt, "word", "s") << " of length " << sz << " or longer" << endl;

	for_each(wc, words.end(), [](const string& s) {cout << s << " "; });
	cout << endl;
}

int main() {
	string word;
	vector<string> words;
	cout << "请输入一些单词：" << endl;
	while (cin >> word) {
		words.push_back(word);
	}

	biggies(words, 4);

	system("pause");
	return 0;
}
*/





//练习10.19		了解partition和stable_partition的区别
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

string make_plural(size_t n, const string& s, const string& ending) {
	return n > 1 ? s + ending : s;
}

void elimDups(vector<string>& words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

inline void myPrint(vector<string>& words) {
	for (auto it = words.begin(); it != words.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
}

inline bool LessFour(const string& s) {
	return s.size() < 4 ? true : false;
}


void biggies(vector<string>& words, vector<string>::size_type sz) {
	elimDups(words);
	stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.size() < b.size(); });

	//两种写法均可
	auto wc = stable_partition(words.begin(), words.end(), LessFour);					//将partition替换为stable_partition即可
	//auto wc = stable_partition(words.begin(), words.end(), [sz](const string& a) {return a.size() < sz; });					//将partition替换为stable_partition即可

	auto cnt = words.end() - wc;
	cout << cnt << " " << make_plural(cnt, "word", "s") << " of length " << sz << " or longer" << endl;

	for_each(wc, words.end(), [](const string& s) {cout << s << " "; });
	cout << endl;
}

int main() {
	string word;
	vector<string> words;
	cout << "请输入一些单词：" << endl;
	while (cin >> word) {
		words.push_back(word);
	}

	biggies(words, 4);

	system("pause");
	return 0;
}
*/



//练习10.20
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

string make_plural(size_t n, const string& s, const string& ending) {
	return n > 1 ? s + ending : s;
}

void elimDups(vector<string>& words) {
	sort(words.begin(), words.end());
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}

inline void myPrint(vector<string>& words) {
	for (auto it = words.begin(); it != words.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
}

void biggies(vector<string>& words, vector<string>::size_type sz) {
	elimDups(words);
	auto cnt = count_if(words.begin(), words.end(), [sz](const string& a) {return a.size() >= sz; });
	cout << cnt << " " << make_plural(cnt, "word", "s") << " of length " << sz << " or longer" << endl;

	cout << endl;
}

int main() {
	string word;
	vector<string> words;
	cout << "请输入一些单词：" << endl;
	while (cin >> word) {
		words.push_back(word);
	}

	biggies(words, 6);

	system("pause");
	return 0;
}
*/




//练习10.21
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

void func(void) {
	int num;
	cout << "请输入一个正数：" << endl;
	cin >> num;

	auto f = [num]()mutable->bool {if (num > 0) { --num; return false; } else return true; };

	for (int i = 0; i < num + 5; ++i) {
		cout << f() << ' ';
	}
	cout << endl;
}

int main() {
	func();

	system("pause");
	return 0;
}
*/




//练习10.22—10.25略



//练习10.27
/*
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
	vector<int> vi = { 2,2,2,4,5,3,9,2,5 };
	list<int> mylist;

	sort(vi.begin(), vi.end());
	unique_copy(vi.cbegin(), vi.cend(), back_inserter(mylist));

	for (auto it = mylist.cbegin(); it != mylist.cend(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/





//练习10.28
/*
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
	vector<int> v = { 1,2,3,4,5 };
	list<int> v1, v2, v3;

	cout<< "原容器：" << endl;
	for (auto i : v) {
		cout << i << ' ';
	}
	cout << endl;
	
	copy(v.cbegin(), v.cend(), inserter(v1, v1.begin()));
	cout << endl<< "inserter结果：" << endl;
	for (auto i : v1) {
		cout << i << ' ';
	}
	cout << endl;

	copy(v.cbegin(), v.cend(), back_inserter(v2));
	cout << endl<< "back_inserter结果：" << endl;
	for (auto i : v2) {
		cout << i << ' ';
	}
	cout << endl;

	copy(v.cbegin(), v.cend(), front_inserter(v3));
	cout << endl<< "front_inserter结果：" << endl;
	for (auto i : v3) {
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/




//练习10.29—10.33略




//练习10.34
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

inline void reversePrint(vector<int> v) {
	for (auto it = v.crbegin(); it != v.crend(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
}

int main() {
	vector<int> v = { 1,2,3,4,5 };
	reversePrint(v);

	system("pause");
	return 0;
}
*/





//练习10.35
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
	vector<int> v = { 1,2,3,4,5 };
	for (auto it = v.cend(); it != v.cbegin();) {				//注意循环条件
		cout << *(--it) << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/





//练习10.36
/*
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
	list<int> li = { 6,0,1,9,0,3,6 };
	auto loc = find(li.crbegin(), li.crend(), 0);				// 使用反向迭代器查找最后一个0
	++loc;						// 将迭代器向链表头方向推进一个位置，使得转换为普通迭代器时，回到最后一个0的位置
	int index = 1;
	for (auto it = li.cbegin(); it != loc.base(); ++it, ++index);				// 用base将loc转换为普通迭代器，并从链表头开始遍历，记录最后一个0的编号

	if (index >= li.size()) {
		cout << "容器中没有0" << endl;
	}
	else {
		cout << "最后一个值为0的元素索引值为：" << index << endl;
	}

	system("pause");
	return 0;
}
*/






//练习10.37
/*
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
	vector<int> vi = { 1,2,3,4,5,6,7,8,9,10 };
	list<int> li;

	vector<int>::reverse_iterator rb(vi.begin() + 7);
	vector<int>::reverse_iterator re(vi.begin() + 2);

	copy(rb, re, back_inserter(li));
	for (auto i : li) {
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/





//练习10.42
/*
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
using namespace std;

void elimDumps(list<string>& words) {
	words.sort();			//使用链表版本的排序代替通用版sort
	words.unique();			//删除同一个值的连续拷贝，没有返回值
}

void myPrint(list<string>& words) {
	for (auto i : words) {
		cout << i << ' ';
	}
	cout << endl;
}

int main() {
	string word;
	list<string> words;

	cout << "请输入一些单词：" << endl;
	while (cin >> word) {
		words.push_back(word);
	}

	cout << endl << "去重前：" << endl;
	myPrint(words);

	elimDumps(words);
	cout << endl << "去重后：" << endl;
	myPrint(words);

	system("pause");
	return 0;
}
*/