#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// string 받음
	string str;
	cin >> str;

	// string 바탕으로 list 생성
	list<char> lt;
	for (auto s : str)
		lt.push_back(s);
	auto iter = lt.end();

	// 명령어 횟수 받음
	int num;
	cin >> num;

	// 명령어 횟수 만큼, for loop
	for (int i = 0; i < num; i++) {
		// 명령어 받음
		char oper;
		cin >> oper;
		if (oper == 'L' && iter != lt.begin()) {
			--iter;
		}
		else if (oper == 'D' && iter != lt.end()) {
			++iter;
		}
		else if (oper == 'B' && iter != lt.begin()) {
			--iter;
			iter = lt.erase(iter);
		}
		else if (oper == 'P') {
			char ch;
			cin >> ch;
			lt.insert(iter, ch);
		}
	}

	for (auto i = lt.begin(); i != lt.end(); i++)
		cout << *i;
}
