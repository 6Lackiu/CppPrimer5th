//��ϰ11.3
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

	cout << "������һЩ���ʣ�" << endl;
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




//��ϰ11.4
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

	cout << "������һЩ���ʣ�" << endl;
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





//��ϰ11.7
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
		cout << f.first << "�ҵĺ��ӣ�";
		for (auto k : f.second) {
			cout << f.first << k << ' ';
		}
		cout << endl;
	}
}

int main() {
	map<string, vector<string>> fams;

	add_fam(fams, "��");
	add_kid(fams, "��", "��");
	add_fam(fams, "��");
	add_kid(fams, "��", "��");
	add_kid(fams, "��", "��");
	add_fam(fams, "��");				//�ٴ���Ӽ�ͥ�����������ԭ��ͥ����Ӱ��
	add_kid(fams, "��", "һ��");
	add_fam(fams, "��");
	add_fam(fams, "��");
	myPrint(fams);

	system("pause");
	return 0;
}
*/





//��ϰ11.8
//vector�汾
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
	cout << "������һЩ���ʣ�" << endl;
	while (cin >> word) {
		trans(word);
		if (find(vs.begin(), vs.end(), word) == vs.end()) {
			vs.push_back(word);
		}
	}

	cout << endl << "�����" << endl;
	for (auto i : vs) {
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/

//set�汾
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
	cout << "������һЩ���ʣ�" << endl;
	while (cin >> word) {
		trans(word);
		mys.insert(word);			//ʹ��insert����set
	}

	cout << endl << "�����" << endl;
	for (auto i : mys) {
		cout << i << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}
*/





//��ϰ11.9
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

	cout << "������һЩ��䣺" << endl;
	while (getline(cin,line)) {
		++lineno;
		istringstream l_in(line);			//�����ַ�������ȡ����
		while (l_in >> word) {
			trans(word);
			word_lineno[word].push_back(lineno);
		}
	}

	for (auto w : word_lineno) {
		cout << w.first << "�����У�";
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





//��ϰ11.12
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
	while (cin >> s && cin >> n) {					//�������ֶ��뷽��
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





//��ϰ11.13
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
	while (cin >> s && cin >> n) {					//�������ֶ��뷽��
		//data.push_back(pair<string, int>(s, n));
		data.push_back({ s,n });			//�б��ʼ�������
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





//��ϰ11.14
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

	addfam(fams, "��");
	addkid(fams, "��", make_pair("��", "1999.10.3"));
	addfam(fams, "��");
	addfam(fams, "��");
	addkid(fams, "��", { "�ɹ�","1998.3.30" });
	addkid(fams, "��", { "��","2000.12.5" });
	addfam(fams, "��");

	for (auto f : fams) {
		cout << f.first << "�ҵĺ����У�" << endl;
		for (auto k : f.second) {
			cout << f.first << k.first << "\t" << "����Ϊ" << k.second << endl;
		}
		cout << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}
*/




//��ϰ11.20
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
	cout << "����һЩ����" << endl;
	while (cin >> word) {
		auto ret = word_count.insert({ word,1 });
		if (!ret.second) {
			++ret.first->second;
		}
	}
	for (const auto& words : word_count) {	
		cout << words.first << "������" << words.second << "��" << endl;
		}
	cout << endl;

	system("pause");
	return 0;
}
*/





//��ϰ11.23
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

	add_kid(fams, "��", "ǿ");
	add_kid(fams, "��", "�ɹ�");
	add_kid(fams, "��", "һ��");
	add_kid(fams, "��", "��ǿ");

	for (auto f : fams) {
		cout << f.first << "�ҵĺ��ӣ�" << f.second << endl;
	}

	system("pause");
	return 0;
}
*/




//��ϰ11.31
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
		cout << "û��" << author << "�������" << endl;
	}
	else {
		books.erase(pos.first, pos.second);
	}
}

void MyPrint(multimap<string, string>& books) {
	cout << "��ǰ��Ŀ������" << endl;
	for (auto& book : books) {
		cout << book.first << "�ġ�" << book.second << "��" << endl;
	}
	cout << endl;
}

int main() {
	multimap<string, string> books;
	books.insert({ "����", "��������" });
	books.insert({ "³Ѹ", "�ź�" });
	books.insert({ "�໪", "����" });
	books.insert({ "³Ѹ", "����Ϧʰ" });
	MyPrint(books);
	cout << endl;
	MyRemove(books, "����");
	MyPrint(books);

	MyRemove(books, "����");
	MyPrint(books);

	system("pause");
	return 0;
}
*/





//��ϰ11.33		����ת������			**����**
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
	ifstream map_file("D:\\C++Projects\\C++ Primer\\��ʮһ�� ��������\\��ʮһ�� ��������\\transmap.txt");
	ifstream input("D:\\C++Projects\\C++ Primer\\��ʮһ�� ��������\\��ʮһ�� ��������\\input.txt");
	word_transform(map_file, input);

	system("pause");
	return 0;
}
*/






//��ϰ11.38
//���ʼ���
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

	cout << "������һЩ���ʣ�" << endl;
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


//����ת��
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
	ifstream map_file("D:\\C++Projects\\C++ Primer\\��ʮһ�� ��������\\��ʮһ�� ��������\\unordered_transmap.txt");
	ifstream input("D:\\C++Projects\\C++ Primer\\��ʮһ�� ��������\\��ʮһ�� ��������\\unordered_input.txt");
	word_transform(map_file, input);

	system("pause");
	return 0;
}
*/