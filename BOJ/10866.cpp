#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num_oper;
	cin >> num_oper;

	deque<int> dq;

	while (num_oper--) {
		string oper;
		cin >> oper;

		if (oper[0] == 'f') {
			if (dq.size() > 0) {
				cout << dq.front() << '\n';
			}
			else
				cout << "-1\n";
		}
		else if (oper[0] == 'b') {
			if (dq.size() > 0) {
				cout << dq.back() << '\n';
			}
			else
				cout << "-1\n";
		}
		else if (oper[0] == 's') {
			cout << dq.size() << '\n';
		}
		else if (oper[0] == 'e') {
			cout << dq.empty() << '\n';
		}
		else if (oper[5] == 'f') {
			int num;
			cin >> num;
			dq.push_front(num);
		}
		else if (oper[5] == 'b') {
			int num;
			cin >> num;
			dq.push_back(num);
		}
		else if (oper[4] == 'f') {
			if (dq.size() > 0) {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else
				cout << "-1\n";
		}
		else if (oper[4] == 'b') {
			if (dq.size() > 0) {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else
				cout << "-1\n";
		}
	}
}