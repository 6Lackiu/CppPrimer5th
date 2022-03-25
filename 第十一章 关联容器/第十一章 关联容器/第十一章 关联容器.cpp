//练习11.3
/*
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<numeric> 
#include<iostream>
using namespace std;

int main() {
	map<string, size_t> word_count;
	string word;

	cout << "请输入一些单词：" << endl;
	while (cin >> word) {
		++word_count[word];
	}

	for (const auto& w : word_count) {
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times." : " time.") << endl;
	}


	system("pause");
	return 0;
}
*/




//练习11.4
/*
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<numeric>
#include<iostream>
using namespace std;

string trans(string& s) {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] -= ('A' - 'a');
		}
		else if (s[i] == '.' || s[i] == ',') {
			s.erase(i, 1);
		}
	}
	return s;
}

int main() {
	map<string, size_t>  word_count;
	string word;

	cout << "请输入一些单词：" << endl;
	while (cin >> word) {
		++word_count[trans(word)];
	}

	for (const auto& w : word_count) {
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times." : " time.") << endl;
	}

	system("pause");
	return 0;
}
*/





//练习11.7
/*
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<numeric>
#include<iostream>
using namespace std;

inline void add_fam(map<string, vector<string>>& fams, const string& fam) {
	fams[fam];
}

inline void add_kid(map<string, vector<string>>& fams, const string& fam, const string& kid) {
	fams[fam].push_back(kid);
}

inline void myPrint(map<string, vector<string>>& fams) {
	for (auto f : fams) {
		cout << f.first << "家的孩子：";
		for (auto k : f.second) {
			cout << f.first << k << ' ';
		}
		cout << endl;
	}
}

int main() {
	map<string, vector<string>> fams;

	add_fam(fams, "刘");
	add_kid(fams, "张", "红");
	add_fam(fams, "李");
	add_kid(fams, "刘", "阳");
	add_kid(fams, "李", "刚");
	add_fam(fams, "刘");				//再次添加家庭“刘”不会对原家庭产生影响
	add_kid(fams, "李", "一凡");
	add_fam(fams, "张");
	add_fam(fams, "杨");
	myPrint(fams);

	system("pause");
	return 0;
}
*/





//练习11.8
//vector版本
/*
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<numeric>
#include<iostream>
using namespace std;

inline void trans(string& s) {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] -= ('A' - 'a');
		}
		else if (s[i] == ',' || s[i] == '.') {
			s.erase(i, 1);
		}
	}
}

int main() {
	vector<string> vs;
	string word;
	cout << "请输入一些单词：" << endl;
	while (cin >> word) {
		trans(word);
		if (find(vs.begin(), vs.end(), word) == vs.end()) {
			vs.push_back(word);
		}
	}

	cout << endl << "输出：" << endl;
	for (auto i : vs) {
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/

//set版本
/*
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<numeric>
#include<iostream>
using namespace std;

inline void trans(string& s) {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] -= ('A' - 'a');
		}
		else if (s[i] == ',' || s[i] == '.') {
			s.erase(i, 1);
		}
	}
}

int main() {
	set<string> mys;
	string word;
	cout << "请输入一些单词：" << endl;
	while (cin >> word) {
		trans(word);
		mys.insert(word);			//使用insert插入set
	}

	cout << endl << "输出：" << endl;
	for (auto i : mys) {
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/





//练习11.9
/*
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<numeric>
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;

inline void trans(string& s) {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] -= ('A' - 'a');
		}
		else if (s[i] == ',' || s[i] == '.') {
			s.erase(i, 1);
		}
	}
}

int main() {
	map<string, list<int>> word_lineno;
	string word;
	string line;
	int lineno = 0;

	cout << "请输入一些语句：" << endl;
	while (getline(cin,line)) {
		++lineno;
		istringstream l_in(line);			//创造字符流，读取单词
		while (l_in >> word) {
			trans(word);
			word_lineno[word].push_back(lineno);
		}
	}

	for (auto w : word_lineno) {
		cout << w.first << "所在行：";
		for (auto i : w.second) {
			cout << i << ' ';
		}
		cout << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}
*/





//练习11.12
/*
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<utility>
#include<numeric>
#include<iostream>
using namespace std;

int main() {
	vector<pair<string, int>> data;
	string s;
	int n;
	while (cin >> s && cin >> n) {					//留意这种读入方法
		data.push_back(pair<string, int>(s, n));
	}
	for (auto p : data) {
		cout << p.first << '\t' << p.second << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}
*/





//练习11.13
/*
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<utility>
#include<numeric>
#include<iostream>
using namespace std;

int main() {
	vector<pair<string, int>> data;
	string s;
	int n;
	while (cin >> s && cin >> n) {					//留意这种读入方法
		//data.push_back(pair<string, int>(s, n));
		data.push_back({ s,n });			//列表初始化，最简单
		//data.push_back(make_pair(s, n));
	}
	for (auto p : data) {
		cout << p.first << '\t' << p.second << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}
*/





//练习11.14
/*
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<utility>
#include<numeric>
#include<iostream>
using namespace std;

inline void addfam(map<string, vector<pair<string, string>>>& fams, const string& fam) {
	fams[fam];
}

inline void addkid(map<string, vector<pair<string, string>>>& fams, const string& fam, pair<string,string> p) {
	fams[fam].push_back({ p.first,p.second });
}

int main() {
	map<string, vector<pair<string, string>>> fams;

	addfam(fams, "刘");
	addkid(fams, "刘", make_pair("永", "1999.10.3"));
	addfam(fams, "张");
	addfam(fams, "刘");
	addkid(fams, "张", { "成功","1998.3.30" });
	addkid(fams, "刘", { "浩","2000.12.5" });
	addfam(fams, "李");

	for (auto f : fams) {
		cout << f.first << "家的孩子有：" << endl;
		for (auto k : f.second) {
			cout << f.first << k.first << "\t" << "生日为" << k.second << endl;
		}
		cout << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}
*/




//练习11.20
/*
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<utility>
#include<numeric>
#include<iostream>
using namespace std;

int main() {
	map<string, size_t> word_count;
	string word;
	cout << "输入一些单词" << endl;
	while (cin >> word) {
		auto ret = word_count.insert({ word,1 });
		if (!ret.second) {
			++ret.first->second;
		}
	}
	for (const auto& words : word_count) {	
		cout << words.first << "出现了" << words.second << "次" << endl;
		}
	cout << endl;

	system("pause");
	return 0;
}
*/





//练习11.23
/*
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<numeric>
#include<iostream>
using namespace std;

void add_kid(multimap<string, string>& fams, const string& fam, const string& kid) {
	fams.insert({ fam,kid });
}

int main() {
	multimap<string, string> fams;

	add_kid(fams, "刘", "强");
	add_kid(fams, "张", "成功");
	add_kid(fams, "刘", "一刚");
	add_kid(fams, "李", "三强");

	for (auto f : fams) {
		cout << f.first << "家的孩子：" << f.second << endl;
	}

	system("pause");
	return 0;
}
*/




//练习11.31
/*
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<numeric>
#include<iostream>
using namespace std;

void MyRemove(multimap<string, string>& books, const string& author) {
	auto pos = books.equal_range(author);
	if (pos.first == pos.second) {
		cout << "没有" << author << "这个作者" << endl;
	}
	else {
		books.erase(pos.first, pos.second);
	}
}

void MyPrint(multimap<string, string>& books) {
	cout << "当前书目包括：" << endl;
	for (auto& book : books) {
		cout << book.first << "的《" << book.second << "》" << endl;
	}
	cout << endl;
}

int main() {
	multimap<string, string> books;
	books.insert({ "老舍", "骆驼祥子" });
	books.insert({ "鲁迅", "呐喊" });
	books.insert({ "余华", "活着" });
	books.insert({ "鲁迅", "朝花夕拾" });
	MyPrint(books);
	cout << endl;
	MyRemove(books, "老舍");
	MyPrint(books);

	MyRemove(books, "冰心");
	MyPrint(books);

	system("pause");
	return 0;
}
*/





//练习11.33		单词转换程序			**多做**
/*
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<numeric>
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;

void word_transform(ifstream& map_file, ifstream& input);
map<string, string> buildMap(ifstream& map_file);
const string& transform(const string& s, const map<string, string>& m);

void word_transform(ifstream& map_file, ifstream& input) {
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text)) {
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword) {
				firstword = false;
			}
			else {
				cout << ' ';
			}
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

map<string, string> buildMap(ifstream& map_file) {
	map<string, string> trans_map;
	string key, value;
	while (map_file >> key && getline(map_file, value)) {
		if (value.size() > 1) {
			trans_map[key] = value.substr(1);
		}
		else {
			throw runtime_error("no rule for" + key);
		}
	}
	return trans_map;
}

const string& transform(const string& s, const map<string, string>& m) {
	auto map_it = m.find(s);
	if (map_it != m.cend()) {
		return map_it->second;
	}
	else {
		return s;
	}
}

int main() {
	ifstream map_file("D:\\C++Projects\\C++ Primer\\第十一章 关联容器\\第十一章 关联容器\\transmap.txt");
	ifstream input("D:\\C++Projects\\C++ Primer\\第十一章 关联容器\\第十一章 关联容器\\input.txt");
	word_transform(map_file, input);

	system("pause");
	return 0;
}
*/






//练习11.38
//单词计数
/*
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<numeric> 
#include<iostream>
using namespace std;

int main() {
	unordered_map<string, size_t> word_count;
	string word;

	cout << "请输入一些单词：" << endl;
	while (cin >> word) {
		++word_count[word];
	}

	for (const auto& w : word_count) {
		cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times." : " time.") << endl;
	}


	system("pause");
	return 0;
}
*/


//单词转换
/*
#include<vector>
#include<string>
#include<list>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<numeric>
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;

void word_transform(ifstream& map_file, ifstream& input);
unordered_map<string, string> buildMap(ifstream& map_file);
const string& transform(const string& s, const unordered_map<string, string>& m);

void word_transform(ifstream& map_file, ifstream& input) {
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text)) {
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword) {
				firstword = false;
			}
			else {
				cout << ' ';
			}
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

unordered_map<string, string> buildMap(ifstream& map_file) {
	unordered_map<string, string> trans_map;
	string key, value;
	while (map_file >> key && getline(map_file, value)) {
		if (value.size() > 1) {
			trans_map[key] = value.substr(1);
		}
		else {
			throw runtime_error("no rule for" + key);
		}
	}
	return trans_map;
}

const string& transform(const string& s, const unordered_map<string, string>& m) {
	auto map_it = m.find(s);
	if (map_it != m.cend()) {
		return map_it->second;
	}
	else {
		return s;
	}
}

int main() {
	ifstream map_file("D:\\C++Projects\\C++ Primer\\第十一章 关联容器\\第十一章 关联容器\\unordered_transmap.txt");
	ifstream input("D:\\C++Projects\\C++ Primer\\第十一章 关联容器\\第十一章 关联容器\\unordered_input.txt");
	word_transform(map_file, input);

	system("pause");
	return 0;
}
*/