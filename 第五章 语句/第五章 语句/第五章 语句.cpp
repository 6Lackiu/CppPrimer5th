//��ϰ5.9
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string s;
	int cnt = 0;
	cin >> s;
	for (auto c : s) {
		if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u')) {
			++cnt;
		}
	}
	cout << "��" << cnt << "��Ԫ����ĸ" << endl;
	system("pause");
	return 0;
}
*/



//��ϰ5.10
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string s;
	int acnt = 0, ecnt = 0, icnt = 0, ocnt = 0, ucnt = 0;
	cin >> s;
	for (auto c : s) {
		switch (c) {
		case 'a':
		case 'A':
			++acnt;
			break;
		case 'e':
		case 'E':
			++ecnt;
			break;
		case 'i':
		case 'I':
			++icnt;
			break;
		case 'o':
		case 'O':
			++ocnt;
			break;
		case 'u':
		case 'U':
			++ucnt;
			break;
		default:
			break;
		}
	}
	cout << "a:" << acnt << "   e:" << ecnt << "   i:" << icnt << "   o:" << ocnt << "   u:" << ucnt << endl;
	system("pause");
	return 0;
}
*/




//��ϰ5.12
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string s;
	int ffcnt = 0, flcnt = 0, ficnt = 0;
	cin >> s;
	char pre = ' ';
	bool flag = true;
	for (auto c : s) {
		if (pre == 'f') {
			if (c == 'f') {
				++ffcnt;
				flag = false;
			}
			else if (c == 'l') ++flcnt;
			else if (c == 'i') ++ficnt;
		}
		if (!flag) {
			pre = '\0';
			flag = true;
		}
		else {
			pre = c;
		}
	}
	cout << "ff:" << ffcnt << "   fl:" << flcnt << "   fi:" << ficnt << endl;
	system("pause");
	return 0;
}
*/




//��ϰ5.14
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string currstr = " ", prestr = " ", maxstr = " ";
	int cnt = 1, max = 0;
	while (cin >> currstr) {
		if (currstr == prestr) {
			++cnt;
			if (cnt > max) {
				max = cnt;
				maxstr = currstr;
			}
		}
		else {
			cnt = 1;
		}
		prestr = currstr;
	}
	if (max > 1) {
		cout << "���ִ��������ַ����ǣ�" << maxstr << "   ���ֵĴ���Ϊ��" << max << endl;
	}
	else {
		cout << "ÿ���ַ�����ֻ������һ��" << endl;
	}

	system("pause");
	return 0;
}
*/



//��ϰ5.17
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool func(vector<int> v1, vector<int> v2) {
	int n = (v1.size() < v2.size()) ? v1.size() : v2.size();
	bool flag = true;
	for (int i = 0; i < n; ++i) {
		if (v1[i] != v2[i]) flag = false;
	}
	return flag;
}

int main() {
	vector<int> v1 = { 0,1,1,2 };
	vector<int> v2 = { 0,1,1,2,3,5,8 };
	vector<int> v3 = { 0,1,2,2,3 };
	bool flag = func(v2, v1);
	
	if (flag) cout << "��ǰ׺" << endl;
	else cout << "����ǰ׺" << endl;

	system("pause");
	return 0;
}
*/




//��ϰ5.19
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string s1, s2;
	do {
		cout << "�������һ���ַ�����";
		cin >> s1;
		cout << "������ڶ����ַ�����";
		cin >> s2;
		cout << ((s1.size() < s2.size()) ? s1 : s2 )<< endl;
	} while (cin);
	system("pause");
	return 0;
}
*/




//��ϰ5.20
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string curr = " ", pre = " ";
	bool flag = true;
	while (cin >> curr) {
		if (curr == pre) {
			cout << curr << endl;
			flag = false;
			break;
		}
		pre = curr;
	}
	if (flag) {
		cout << "û�е����������ظ����ֵ�" << endl;
	}
	system("pause");
	return 0;
}
*/




//��ϰ5.21
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string curr = " ", pre = " ";
	bool flag = true;
	while (cin >> curr) {
		if (!isupper(curr[0])) {
			continue;
		}
		if (curr == pre) {
			cout << curr << endl;
			flag = false;
			break;
		}
		pre = curr;
	}
	if (flag) {
		cout << "û�е����������ظ����ֵ�" << endl;
	}
	system("pause");
	return 0;
}
*/




//��ϰ
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {

	system("pause");
	return 0;
}
*/




//��ϰ
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {

	system("pause");
	return 0;
}
*/




//��ϰ
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {

	system("pause");
	return 0;
}
*/




//��ϰ
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {

	system("pause");
	return 0;
}
*/




//��ϰ
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {

	system("pause");
	return 0;
}
*/




//��ϰ
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {

	system("pause");
	return 0;
}
*/




//��ϰ
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {

	system("pause");
	return 0;
}
*/




//��ϰ
/*
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {

	system("pause");
	return 0;
}
*/