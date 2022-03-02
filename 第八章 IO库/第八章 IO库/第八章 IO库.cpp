//��ϰ8.1
/*
#include<iostream>
#include<stdexcept>
using namespace std;

istream& f(istream& in) {
	int v;
	while (in >> v , !in.eof()) {
		if (in.bad()) {
			throw runtime_error("IO������");
		}
		if (in.fail()) {
			cerr << "���ݴ��������ԣ�" << endl;
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
	cout << "������һЩ��������ctrl+z��������" << endl;
	f(cin);

	system("pause");
	return 0;
}
*/



//��ϰ8.4
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
		cerr << "�޷��������ļ�" << endl;
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




//��ϰ8.5
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
		cerr << "�޷��������ļ�" << endl;
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



//��ϰ8.6
/*
#include<iostream>
#include<fstream>
#include<stdexcept>
#include "Sales_data.h"

using namespace std;

int main(int argc , char *argv[]) {
	if (argc != 2) {
		cerr << "������ļ���" << endl;
		return -1;
	}
	
	ifstream input(argv[1]);
	if (!input) {
		cerr << "�޷��������ļ�" << endl;
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
		cerr << "û������" << endl;
		return -1;
	}

	system("pause");
	return 0;
}
*/




//��ϰ8.7
/*
#include<iostream>
#include<fstream>
#include<stdexcept>
#include "Sales_data.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cerr << "��������롢����ļ���" << endl;
		return -1;
	}

	ifstream input(argv[1]);
	if (!input) {
		cerr << "�޷��������ļ�" << endl;
		return -1;
	}

	ofstream output(argv[2]);
	if (!output) {
		cerr << "�޷�������ļ�" << endl;
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
		cerr << "û������" << endl;
		return -1;
	}

	system("pause");
	return 0;
}
*/




//��ϰ8.8
/*
#include<iostream>
#include<fstream>
#include<stdexcept>
#include "Sales_data.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cerr << "��������롢����ļ���" << endl;
		return -1;
	}

	ifstream input(argv[1]);
	if (!input) {
		cerr << "�޷��������ļ�" << endl;
		return -1;
	}

	ofstream output(argv[2], ofstream::app);
	if (!output) {
		cerr << "�޷�������ļ�" << endl;
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
		cerr << "û������" << endl;
		return -1;
	}

	system("pause");
	return 0;
}
*/



//��ϰ8.9
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
		cerr << "�޷��������ļ�" << endl;
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




//��ϰ8.10
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
		cerr << "�ļ���ʧ�ܣ�" << endl;
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




//��ϰ8.11
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




//��ϰ8.13
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
	//�����֤�绰���뽫�ڵ�17�½���
	//���ڼ򵥷���true
	return true;
}

int main(int argc,char* argv[]) {
	string line, word;		//�ֱ𱣴����������һ�к͵���
	vector<PersonInfo> people;			//����������������м�¼
	istringstream record;

	if (argc != 2) {
		cerr << "������ļ���" << endl;
		return -1;
	}

	ifstream in(argv[1]);
	if (!in) {
		cerr << "�޷��������ļ�" << endl;
		return -1;
	}

	while (getline(in, line)) {
		PersonInfo info;				//����һ������˼�¼�Ķ���
		record.clear();					//�ظ�ʹ���ַ�����ʱ��ÿ�ζ�Ҫ����clear
		record.str(line);					//����¼�󶨵��ն������
		record >> info.name;		//��ȡ����
		while (record >> word) {				//��ȡ�绰����
			info.phones.push_back(word);				//��������
		}
		people.push_back(info);				//���μ�¼׷�ӵ�peopleĩβ
	}

	ostringstream os;
	for (const auto& entry : people) {								//��people��ÿһ��
		ostringstream formatted, badNums;						//ÿ��ѭ���������Ķ���
		for (const auto& nums : entry.phones) {				//��ÿ����
			if (!valid(nums)) {
				badNums << "  " << nums;							//�������ַ�����ʽ����badNums
			}
			else {
				formatted << "  " << format(nums);				//����ʽ�����ַ�����д�롱formatted
			}

			if (badNums.str().empty()) {				//û�д������
				os << entry.name << "  " << formatted.str() << endl;			//��ӡ���ֺ͸�ʽ������
			}
			else {
				cerr << "input error:" << entry.name << "invalid number(s)" << badNums.str() << endl;			//���򣬴�ӡ���ֺʹ������
			}
		}
	}
	cout << os.str() << endl;

	system("pause");
	return 0;
}
*/