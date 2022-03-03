//��ϰ10.1
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



//��ϰ10.2
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




//��ϰ10.3
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




//��ϰ10.6
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
	cout << "����ǰ��" << endl;
	for (auto i : vi) {
		cout << i << ' ';
	}
	cout << endl << "���ĺ�" << endl;

	fill_n(vi.begin(), vi.size(), 0);
	for (auto i = vi.begin(); i != vi.end();++i) {
		cout << *i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/



//��ϰ10.9
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
	cout << "��ʼwords��" << endl;
	printWord(words);

	sort(words.begin(), words.end());
	cout << "�����words��" << endl;
	printWord(words);

	auto end_unique = unique(words.begin(), words.end());
	cout << "����unique��words��" << endl;
	printWord(words);

	words.erase(end_unique, words.end());
	cout << "ȥ�غ�words��" << endl;
	printWord(words);
}

int main() {
	string word;
	vector<string> words;
	cout << "������һЩ���ʣ�" << endl;
	
	while (cin >> word) {
		words.push_back(word);
	}
	elimDups(words);

	system("pause");
	return 0;
}
*/



//��ϰ10.11
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
	cout << "��ʼwords��" << endl;
	printWord(words);

	sort(words.begin(), words.end());
	cout << "�����words��" << endl;
	printWord(words);

	auto end_unique = unique(words.begin(), words.end());
	cout << "����unique��words��" << endl;
	printWord(words);

	words.erase(end_unique, words.end());
	cout << "ȥ�غ�words��" << endl;
	printWord(words);
}

bool isShorter(const string& s1, const string& s2) {
	return s1.size() < s2.size();
}

int main() {
	string word;
	vector<string> words;
	cout << "������һЩ���ʣ�" << endl;

	while (cin >> word) {
		words.push_back(word);
	}

	elimDups(words);

	stable_sort(words.begin(), words.end(), isShorter);
	cout<<"stable_sort��"<<endl;
	printWord(words);

	system("pause");
	return 0;
}
*/




//��ϰ10.13
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
	cout << "������һЩ���ʣ�" << endl;
	while (cin >> word) {
		words.push_back(word);
	}
	cout << "����partitionǰ��" << endl;
	myPrint(words.begin(), words.end());

	auto it = partition(words.begin(), words.end(), FivePlus);
	cout << endl << "����partition��" << endl;
	myPrint(words.begin(), words.end());

	system("pause");
	return 0;
}
*/




//��ϰ10.14
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




//��ϰ10.15
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





//��ϰ10.16	����ȫ�棬�������
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
	cout << "������һЩ���ʣ�" << endl;
	while (cin >> word) {
		words.push_back(word);
	}

	biggies(words, 4);

	system("pause");
	return 0;
}
*/





//��ϰ10.18
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

	//����д������
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
	cout << "������һЩ���ʣ�" << endl;
	while (cin >> word) {
		words.push_back(word);
	}

	biggies(words, 4);

	system("pause");
	return 0;
}
*/





//��ϰ10.19		�˽�partition��stable_partition������
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

	//����д������
	auto wc = stable_partition(words.begin(), words.end(), LessFour);					//��partition�滻Ϊstable_partition����
	//auto wc = stable_partition(words.begin(), words.end(), [sz](const string& a) {return a.size() < sz; });					//��partition�滻Ϊstable_partition����

	auto cnt = words.end() - wc;
	cout << cnt << " " << make_plural(cnt, "word", "s") << " of length " << sz << " or longer" << endl;

	for_each(wc, words.end(), [](const string& s) {cout << s << " "; });
	cout << endl;
}

int main() {
	string word;
	vector<string> words;
	cout << "������һЩ���ʣ�" << endl;
	while (cin >> word) {
		words.push_back(word);
	}

	biggies(words, 4);

	system("pause");
	return 0;
}
*/



//��ϰ10.20
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
	cout << "������һЩ���ʣ�" << endl;
	while (cin >> word) {
		words.push_back(word);
	}

	biggies(words, 6);

	system("pause");
	return 0;
}
*/




//��ϰ10.21
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

void func(void) {
	int num;
	cout << "������һ��������" << endl;
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




//��ϰ10.22��10.25��



//��ϰ10.27
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





//��ϰ10.28
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

	cout<< "ԭ������" << endl;
	for (auto i : v) {
		cout << i << ' ';
	}
	cout << endl;
	
	copy(v.cbegin(), v.cend(), inserter(v1, v1.begin()));
	cout << endl<< "inserter�����" << endl;
	for (auto i : v1) {
		cout << i << ' ';
	}
	cout << endl;

	copy(v.cbegin(), v.cend(), back_inserter(v2));
	cout << endl<< "back_inserter�����" << endl;
	for (auto i : v2) {
		cout << i << ' ';
	}
	cout << endl;

	copy(v.cbegin(), v.cend(), front_inserter(v3));
	cout << endl<< "front_inserter�����" << endl;
	for (auto i : v3) {
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/




//��ϰ10.29��10.33��




//��ϰ10.34
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





//��ϰ10.35
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main() {
	vector<int> v = { 1,2,3,4,5 };
	for (auto it = v.cend(); it != v.cbegin();) {				//ע��ѭ������
		cout << *(--it) << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/





//��ϰ10.36
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
	auto loc = find(li.crbegin(), li.crend(), 0);				// ʹ�÷���������������һ��0
	++loc;						// ��������������ͷ�����ƽ�һ��λ�ã�ʹ��ת��Ϊ��ͨ������ʱ���ص����һ��0��λ��
	int index = 1;
	for (auto it = li.cbegin(); it != loc.base(); ++it, ++index);				// ��base��locת��Ϊ��ͨ����������������ͷ��ʼ��������¼���һ��0�ı��

	if (index >= li.size()) {
		cout << "������û��0" << endl;
	}
	else {
		cout << "���һ��ֵΪ0��Ԫ������ֵΪ��" << index << endl;
	}

	system("pause");
	return 0;
}
*/






//��ϰ10.37
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





//��ϰ10.42
/*
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
using namespace std;

void elimDumps(list<string>& words) {
	words.sort();			//ʹ������汾���������ͨ�ð�sort
	words.unique();			//ɾ��ͬһ��ֵ������������û�з���ֵ
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

	cout << "������һЩ���ʣ�" << endl;
	while (cin >> word) {
		words.push_back(word);
	}

	cout << endl << "ȥ��ǰ��" << endl;
	myPrint(words);

	elimDumps(words);
	cout << endl << "ȥ�غ�" << endl;
	myPrint(words);

	system("pause");
	return 0;
}
*/