//练习8.1
/*
#include<iostream>
#include<stdexcept>
using namespace std;

istream& f(istream& in) {
	int v;
	while (in >> v , !in.eof()) {
		if (in.bad()) {
			throw runtime_error("IO流错误");
		}
		if (in.fail()) {
			cerr << "数据错误，请重试：" << endl;
			in.clear();
			in.ignore(100, '\n');
			continue;
		}

		cout << v << endl;
	}
	in.clear();
	return in;
}

int main() {
	cout << "请输入一些整数，按ctrl+z结束输入" << endl;
	f(cin);

	system("pause");
	return 0;
}
*/



//练习8.4
/*
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stdexcept>
using namespace std;

int main() {
	ifstream input("test8.4.txt");
	if (!input) {
		cerr << "无法打开输入文件" << endl;
		return -1;
	}

	string line;
	vector<string> v;
	while (getline(input, line)) {
		v.push_back(line);
	}

	input.close();

	for (auto i : v) {
		cout << i << endl;
	}

	system("pause");
	return 0;
}
*/




//练习8.5
/*
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<stdexcept>
using namespace std;

int main() {
	ifstream input("test8.4.txt");
	if (!input) {
		cerr << "无法打开输入文件" << endl;
	}

	string word;
	vector<string>v;
	while (input >> word) {
		v.push_back(word);
	}

	input.close();

	for (vector<string>::const_iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}

	system("pause");
	return 0;
}
*/



//练习8.6
/*
#include<iostream>
#include<fstream>
#include<stdexcept>
#include "Sales_data.h"

using namespace std;

int main(int argc , char *argv[]) {
	if (argc != 2) {
		cerr << "请给出文件名" << endl;
		return -1;
	}
	
	ifstream input(argv[1]);
	if (!input) {
		cerr << "无法打开输入文件" << endl;
		return -1;
	}

	Sales_data total;
	if (read(input, total)) {
		Sales_data trans;
		while (read(input, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else {
		cerr << "没有数据" << endl;
		return -1;
	}

	system("pause");
	return 0;
}
*/




//练习8.7
/*
#include<iostream>
#include<fstream>
#include<stdexcept>
#include "Sales_data.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cerr << "请给出输入、输出文件名" << endl;
		return -1;
	}

	ifstream input(argv[1]);
	if (!input) {
		cerr << "无法打开输入文件" << endl;
		return -1;
	}

	ofstream output(argv[2]);
	if (!output) {
		cerr << "无法打开输出文件" << endl;
		return -1;
	}

	Sales_data total;
	if (read(input, total)) {
		Sales_data trans;
		while (read(input, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(output, total) << endl;
				total = trans;
			}
		}
		print(output, total) << endl;
	}
	else {
		cerr << "没有数据" << endl;
		return -1;
	}

	system("pause");
	return 0;
}
*/




//练习8.8
/*
#include<iostream>
#include<fstream>
#include<stdexcept>
#include "Sales_data.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cerr << "请给出输入、输出文件名" << endl;
		return -1;
	}

	ifstream input(argv[1]);
	if (!input) {
		cerr << "无法打开输入文件" << endl;
		return -1;
	}

	ofstream output(argv[2], ofstream::app);
	if (!output) {
		cerr << "无法打开输出文件" << endl;
		return -1;
	}

	Sales_data total;
	if (read(input, total)) {
		Sales_data trans;
		while (read(input, trans)) {
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else {
				print(output, total) << endl;
				total = trans;
			}
		}
		print(output, total) << endl;
	}
	else {
		cerr << "没有数据" << endl;
		return -1;
	}

	system("pause");
	return 0;
}
*/



//练习8.9
/*
#include<iostream>
#include<stdexcept>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

int main() {
	ifstream in("test8.4.txt");
	if (!in) {
		cerr << "无法打开输入文件" << endl;
		return -1;
	}

	string line;
	vector<string> words;
	while (getline(in, line)) {
		words.push_back(line);
	}
	in.close();

	for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it) {
		istringstream line_str(*it);
		string word;
		while (line_str >> word) {
			cout << word << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
*/




//练习8.10
/*
#include<iostream>
#include<stdexcept>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

int main() {
	ifstream in("test8.4.txt");
	if (!in) {
		cerr << "文件打开失败！" << endl;
		return -1;
	}

	string line;
	vector<string> words;
	while (getline(in, line)) {
		words.push_back(line);
	}

	for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it) {
		istringstream line_str(*it);
		string word;
		while (line_str >> word) {
			cout << word << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
*/




//练习8.11
/*
#include<iostream>
#include<stdexcept>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};

int main() {
	string line, word;
	vector<PersonInfo> people;
	istringstream record;

	while (getline(cin, line)) {
		record.clear();
		PersonInfo info;
		record.str(line);
		record >> info.name;

		while (record >> word) {
			info.phones.push_back(word);
		}
		people.push_back(info);
	}

	system("pause");
	return 0;
}
*/




//练习8.13
/*
#include<iostream>
#include<stdexcept>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

struct PersonInfo {
	string name;
	vector<string> phones;
};

string format(const string& s) {
	return s;

}

bool valid(const string& s) {
	//如何验证电话号码将在第17章介绍
	//现在简单返回true
	return true;
}

int main(int argc,char* argv[]) {
	string line, word;		//分别保存来自输入的一行和单词
	vector<PersonInfo> people;			//保存来自输入的所有记录
	istringstream record;

	if (argc != 2) {
		cerr << "请给出文件名" << endl;
		return -1;
	}

	ifstream in(argv[1]);
	if (!in) {
		cerr << "无法打开输入文件" << endl;
		return -1;
	}

	while (getline(in, line)) {
		PersonInfo info;				//创建一个保存此记录的对象
		record.clear();					//重复使用字符串流时，每次都要调用clear
		record.str(line);					//将记录绑定到刚读入的行
		record >> info.name;		//读取名字
		while (record >> word) {				//读取电话号码
			info.phones.push_back(word);				//保存它们
		}
		people.push_back(info);				//将次记录追加到people末尾
	}

	ostringstream os;
	for (const auto& entry : people) {								//对people中每一项
		ostringstream formatted, badNums;						//每个循环步创建的对象
		for (const auto& nums : entry.phones) {				//对每个数
			if (!valid(nums)) {
				badNums << "  " << nums;							//将数的字符串形式存入badNums
			}
			else {
				formatted << "  " << format(nums);				//将格式化的字符串“写入”formatted
			}

			if (badNums.str().empty()) {				//没有错误的数
				os << entry.name << "  " << formatted.str() << endl;			//打印名字和格式化的数
			}
			else {
				cerr << "input error:" << entry.name << "invalid number(s)" << badNums.str() << endl;			//否则，打印名字和错误的数
			}
		}
	}
	cout << os.str() << endl;

	system("pause");
	return 0;
}
*/