#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num_oper;
	cin >> num_oper;

	queue<int> q;

	while (num_oper--) {
		string oper;
		cin >> oper;

		if (oper == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (oper == "pop") {
			if (q.size() > 0) {
				cout << q.front() << '\n';
				q.pop();
			}
			else
				cout << "-1\n";
		}
		else if (oper == "front") {
			if (q.size() > 0) {
				cout << q.front() << '\n';
			}
			else
				cout << "-1\n";
		}
		else if (oper == "back") {
			if (q.size() > 0) {
				cout << q.back() << '\n';
			}
			else
				cout << "-1\n";
		}
		else if (oper == "size") {
			cout << q.size() << '\n';
		}
		else if (oper == "empty") {
			cout << q.empty() << '\n';
		}
	}
}