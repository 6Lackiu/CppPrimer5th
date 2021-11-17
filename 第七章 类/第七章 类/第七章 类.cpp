//��ϰ7.1
/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Sales_data {
	Sales_data() {
		units_sold = 0;
		revenue = 0.0;
	}
	string bookNo;
	unsigned units_sold;
	double revenue;
};

int main() {
	Sales_data total;
	cout << "�����뽻�׼�¼��ISBN���������������룩��" << endl;
	if (cin >> total.bookNo>>total.units_sold>>total.revenue) {
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
			if (total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else {
				cout << "ISBN��" << total.bookNo << "\t��������" << total.units_sold << "\t�����룺" << total.revenue << endl;
				total = trans;
			}
		}
		cout << "ISBN��" << total.bookNo << "\t��������" << total.units_sold << "\t�����룺" << total.revenue << endl;
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}
*/


//��ϰ7.2
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Sales_data {
private:
	string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;	//ԭʼ�۸�
	double saleprice = 0.0;	//ʵ�ۼ۸�
	double discount = 0.0;		//�ۿ�

public:
	string isbn() const {
		return bookNo;
	}

	Sales_data& combine(const Sales_data& rhs) {
		units_sold += rhs.units_sold;
		saleprice = (saleprice * units_sold + rhs.saleprice * rhs.units_sold) / (units_sold + rhs.units_sold);
		if (!sellingprice) {
			discount = saleprice / sellingprice;
		}
		return *this;
	}
};

int main() {


	system("pause");
	return 0;
}
*/



//��ϰ7.3
/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Sales_data {
public:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	string isbn() const {
		return bookNo;
	}

	Sales_data& combine(const Sales_data& rhs) {
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		return *this;
	}
};

int main() {
	Sales_data total;
	cout << "�����뽻�׼�¼��ISBN���������������룩��" << endl;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
			if (total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else {
				cout << "ISBN��" << total.bookNo << "\t��������" << total.units_sold << "\t�����룺" << total.revenue << endl;
				total = trans;
			}
		}
		cout << "ISBN��" << total.bookNo << "\t��������" << total.units_sold << "\t�����룺" << total.revenue << endl;
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}
*/




//��ϰ7.4 ��ϰ7.5
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Person {
private:
	string m_name;
	string m_address;
public:
	string getName() const {
		return m_name;
	}
	string getAddress() const {
		return m_address;
	}
};

int main() {


	system("pause");
	return 0;
}
*/




//��ϰ7.6 ��ϰ7.7
/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Sales_data {
public:
	string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;	//ԭʼ�۸�
	double saleprice = 0.0;	//ʵ�ۼ۸�
	double discount = 0.0;		//�ۿ�
	double revenue = 0.0;		//����

public:
	string isbn() const {
		return bookNo;
	}

	Sales_data& combine(const Sales_data& rhs) {
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		if (!sellingprice) {
			discount = saleprice / sellingprice;
		}
		return *this;
	}
};

istream& read(istream& is, Sales_data& sd) {
	is >> sd.bookNo >> sd.units_sold >> sd.saleprice;
	sd.revenue = (sd.units_sold) * (sd.saleprice);
	return is;
}

ostream& print(ostream& os, const Sales_data& sd) {
	os << "ISBN��" << sd.isbn() << "\t��������" <<sd.units_sold << "\t�����룺" << sd.revenue << endl;
	return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

int main() {
	Sales_data total;
	cout << "�����뽻�׼�¼��ISBN����������ʵ���ۼۣ���" << endl;
	if (read(cin, total)) {
		Sales_data trans;
		while (read(cin, trans)) {
			if (total.isbn() == trans.isbn()) {
				total = add(total, trans);
			}
			else {
				print(cout, total);
				total = trans;
			}
		}
		print(cout, total);
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}
*/




//��ϰ7.9
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Person {
public:
	string m_name;
	string m_address;
public:
	string getName() const {
		return m_name;
	}
	string getAddress() const {
		return m_address;
	}
};

istream& read(istream& is, Person& p) {
	is >> p.m_name >> p.m_address;
	return is;
}

ostream& print(ostream& os, Person& p) {
	os << "������" << p.getName() << "\tסַ��" << p.getAddress() << endl;
	return os;
}

int main() {


	system("pause");
	return 0;
}
*/




//��ϰ7.11
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Sales_data {
public:
	Sales_data() = default;
	Sales_data(const string& book) :bookNo(book) {}
	Sales_data(const string& book, const unsigned num, const double sellp, const double salep);
	Sales_data(istream& is);

public:
	string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;
	double saleprice = 0.0;
	double discount = 0.0;
};

Sales_data::Sales_data(const string& book, const unsigned num, const double sellp, const double salep) {
	bookNo = book;
	units_sold = num;
	sellingprice = sellp;
	saleprice = salep;

	if (sellingprice!=0) {
		discount = saleprice / sellingprice;
	}
}

Sales_data::Sales_data(istream& is) {
	is >> this->bookNo >> this->units_sold >> this->sellingprice >> this->saleprice;
	if (sellingprice != 0) {
		discount = saleprice / sellingprice;
	}
}

int main() {
	Sales_data data1;
	Sales_data data2("001");
	Sales_data data3("002", 100, 200, 180);
	cout << "��������š�������ԭ�ۡ�ʵ���ۼ�" << endl;
	Sales_data data4(cin);

	cout << "�鼮����������ǣ�" << endl;
	cout << "��ţ�" << data1.bookNo << "\t������" << data1.units_sold << "\tԭ�ۣ�" << data1.sellingprice << "\tʵ���ۼۣ�" << data1.saleprice << "\t�ۿۣ�" << data1.discount << endl;
	cout << "��ţ�" << data2.bookNo << "\t������" << data2.units_sold << "\tԭ�ۣ�" << data2.sellingprice << "\tʵ���ۼۣ�" << data2.saleprice << "\t�ۿۣ�" << data2.discount << endl;
	cout << "��ţ�" << data3.bookNo << "\t������" << data3.units_sold << "\tԭ�ۣ�" << data3.sellingprice << "\tʵ���ۼۣ�" << data3.saleprice << "\t�ۿۣ�" << data3.discount << endl;
	cout << "��ţ�" << data4.bookNo << "\t������" << data4.units_sold << "\tԭ�ۣ�" << data4.sellingprice << "\tʵ���ۼۣ�" << data4.saleprice << "\t�ۿۣ�" << data4.discount << endl;

	system("pause");
	return 0;
}
*/




//��ϰ7.12
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Sales_data {
public:
	Sales_data() = default;
	Sales_data(const string& book) :bookNo(book) {}
	Sales_data(const string& book, const unsigned num, const double sellp, const double salep);
	Sales_data(istream& is) {
		is >> this->bookNo >> this->units_sold >> this->sellingprice >> this->saleprice;
		if (sellingprice != 0) {
			discount = saleprice / sellingprice;
		}
	}

public:
	string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;
	double saleprice = 0.0;
	double discount = 0.0;
};

Sales_data::Sales_data(const string& book, const unsigned num, const double sellp, const double salep) {
	bookNo = book;
	units_sold = num;
	sellingprice = sellp;
	saleprice = salep;

	if (sellingprice != 0) {
		discount = saleprice / sellingprice;
	}
}

int main() {
	Sales_data data1;
	Sales_data data2("001");
	Sales_data data3("002", 100, 200, 180);
	cout << "��������š�������ԭ�ۡ�ʵ���ۼ�" << endl;
	Sales_data data4(cin);

	cout << "�鼮����������ǣ�" << endl;
	cout << "��ţ�" << data1.bookNo << "\t������" << data1.units_sold << "\tԭ�ۣ�" << data1.sellingprice << "\tʵ���ۼۣ�" << data1.saleprice << "\t�ۿۣ�" << data1.discount << endl;
	cout << "��ţ�" << data2.bookNo << "\t������" << data2.units_sold << "\tԭ�ۣ�" << data2.sellingprice << "\tʵ���ۼۣ�" << data2.saleprice << "\t�ۿۣ�" << data2.discount << endl;
	cout << "��ţ�" << data3.bookNo << "\t������" << data3.units_sold << "\tԭ�ۣ�" << data3.sellingprice << "\tʵ���ۼۣ�" << data3.saleprice << "\t�ۿۣ�" << data3.discount << endl;
	cout << "��ţ�" << data4.bookNo << "\t������" << data4.units_sold << "\tԭ�ۣ�" << data4.sellingprice << "\tʵ���ۼۣ�" << data4.saleprice << "\t�ۿۣ�" << data4.discount << endl;

	system("pause");
	return 0;
}
*/




//��ϰ7.13
/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Sales_data {
public:
	string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;	//ԭʼ�۸�
	double saleprice = 0.0;	//ʵ�ۼ۸�
	double discount = 0.0;		//�ۿ�
	double revenue = 0.0;		//����

public:
	//���캯��
	Sales_data(istream& is) {
		is >> this->bookNo >> this->units_sold >> this->saleprice;
		revenue = units_sold * saleprice;
	}

	string isbn() const {
		return bookNo;
	}

	Sales_data& combine(const Sales_data& rhs) {
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;
		if (!sellingprice) {
			discount = saleprice / sellingprice;
		}
		return *this;
	}
};

istream& read(istream& is, Sales_data& sd) {
	is >> sd.bookNo >> sd.units_sold >> sd.saleprice;
	sd.revenue = (sd.units_sold) * (sd.saleprice);
	return is;
}

ostream& print(ostream& os, const Sales_data& sd) {
	os << "ISBN��" << sd.isbn() << "\t��������" << sd.units_sold << "\t�����룺" << sd.revenue << endl;
	return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

int main() {
	cout << "�����뽻�׼�¼��ISBN����������ʵ���ۼۣ���" << endl;
	Sales_data total(cin);
	
	if (cin) {
		Sales_data trans(cin);
		do {
			if (total.isbn() == trans.isbn()) {
				total = add(total, trans);
			}
			else {
				print(cout, total);
				total = trans;
			}
		} while (read(cin, trans));
		print(cout, total);
	}
	else {
		cerr << "No data?!" << endl;
		return -1;
	}
	return 0;
}
*/



//��ϰ7.15
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Person {
public:
	Person() = default;
	Person(const string& name, const string& add) {
		m_name = name;
		m_address = add;
	}
	Person(istream& is) {
		is >> this->m_name >> this->m_address;
	}
	string getName() const {
		return m_name;
	}
	string getAddress() const {
		return m_address;
	}
private:
	string m_name;
	string m_address;
};

int main() {
	system("pause");
	return 0;
}
*/





//��ϰ7.23 ��ϰ7.24
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Screen {
public:
	Screen() = default;
	Screen(unsigned height, unsigned width) {
		m_contents = " ";
	}
	Screen(unsigned height, unsigned width, char c) {
		m_height = height;
		m_width = width;
		m_contents = c;
	}
private:
	unsigned m_height = 0, m_width = 0;		//��Ļ�ĸ߶ȺͿ��
	unsigned m_cursor = 0;		//��굱ǰλ��
	string m_contents;		//��Ļ����
};

int main() {


	system("pause");
	return 0;
}
*/




//��ϰ7.26
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//��ʽ����
class Sales_data1 {
public:
	double avg_price()const {
		if (units_sold)
			return revenue / units_sold;
		else
			return 0;
	}

private:
	double revenue = 0.0;
	int units_sold = 0;
};

//��ʽ����
class Sales_data2 {
public:
	double avg_price()const;

private:
	double revenue = 0.0;
	int units_sold = 0;
};
inline double Sales_data2:: avg_price()const {
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}

int main() {
	system("pause");
	return 0;
}
*/



//��ϰ7.27
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Screen {
public:
	using pos = string::size_type;

	Screen() = default;
	Screen(unsigned ht, unsigned wd) :m_height(ht), m_width(wd), m_contents(ht* wd, ' ') {}
	Screen(unsigned ht, unsigned wd, char c) :m_height(ht),m_width(wd),m_contents(ht*wd,c){}

	Screen& move(pos r, pos c) {
		pos row = r * m_width;
		m_cursor = row + c;
		return *this;
	}

	Screen& set(char c) {
		m_contents[m_cursor] = c;
		return *this;
	}

	Screen& display(ostream& os) {
		os << m_contents;
		return *this;
	}

private:
	unsigned m_height = 0, m_width = 0;		//��Ļ�ĸ߶ȺͿ��
	unsigned m_cursor = 0;		//��굱ǰλ��
	string m_contents;		//��Ļ����
};

int main() {
	Screen myScreen(5, 5, 'x');
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";

	system("pause");
	return 0;
}
*/



//��ϰ7.29
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Screen {
public:
	using pos = string::size_type;

	Screen() = default;
	Screen(unsigned ht, unsigned wd) :m_height(ht), m_width(wd), m_contents(ht* wd, ' ') {}
	Screen(unsigned ht, unsigned wd, char c) :m_height(ht), m_width(wd), m_contents(ht* wd, c) {}

	Screen move(pos r, pos c) {
		pos row = r * m_width;
		m_cursor = row + c;
		return *this;
	}

	Screen set(char c) {
		m_contents[m_cursor] = c;
		return *this;
	}

	Screen display(ostream& os) {
		os << m_contents;
		return *this;
	}

private:
	unsigned m_height = 0, m_width = 0;		//��Ļ�ĸ߶ȺͿ��
	unsigned m_cursor = 0;		//��굱ǰλ��
	string m_contents;		//��Ļ����
};

int main() {
	Screen myScreen(5, 5, 'x');
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";

	system("pause");
	return 0;
}
*/




//��ϰ7.31
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Y;
class X {
public:
	Y* ptr = nullptr;
};

class Y {
public:
	X object;
};

int main() {
	system("pause");
	return 0;
}
*/



//��ϰ7.32
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Window_mgr {
public:
	void clear();
};

class Screen {
	friend void Window_mgr::clear();

public:
	using pos = string::size_type;

	Screen() = default;
	Screen(unsigned ht, unsigned wd) :m_height(ht), m_width(wd), m_contents(ht* wd, ' ') {}
	Screen(unsigned ht, unsigned wd, char c) :m_height(ht), m_width(wd), m_contents(ht* wd, c) {}

	Screen move(pos r, pos c) {
		pos row = r * m_width;
		m_cursor = row + c;
		return *this;
	}

	Screen set(char c) {
		m_contents[m_cursor] = c;
		return *this;
	}

	Screen display(ostream& os) {
		os << m_contents;
		return *this;
	}

private:
	unsigned m_height = 0, m_width = 0;		//��Ļ�ĸ߶ȺͿ��
	unsigned m_cursor = 0;		//��굱ǰλ��
	string m_contents;		//��Ļ����
};

void Window_mgr::clear() {
	Screen myScreen(2, 3, 'X');
	cout << "����֮ǰ�������ǣ�" << endl;
	myScreen.display(cout);
	cout << endl;
	myScreen.m_contents = "none";
	cout << "����֮��������ǣ�" << endl;
	myScreen.display(cout);
	cout << endl;
}

int main() {
	Window_mgr w;
	w.clear();

	system("pause");
	return 0;
}
*/



//��ϰ7.43
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class NoDefault {
public:
	NoDefault(int i):val(i){}

	int val;
};

class C {
public:
	C(int i=100):nd(i){}
	NoDefault nd;
};

int main() {  
	C c;
	cout << c.nd.val << endl;

	system("pause");
	return 0;
}
*/


//��ϰ7.57
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Account {
private:
	string StrName;
	double dAmount = 0.0;
	static double dRate;
};

int main() {
	system("pause");
	return 0;
}
*/