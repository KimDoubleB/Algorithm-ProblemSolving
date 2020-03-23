#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num_oper;
	cin >> num_oper;

	stack <int> st;

	while (num_oper--) {
		string oper;
		cin >> oper;

		if (oper == "push") {
			int num;
			cin >> num;
			st.push(num);
		}
		else if (oper == "pop") {
			if (st.size() > 0) {
				cout << st.top() << "\n";
				st.pop();
			}
			else
				cout << "-1\n";
		}
		else if (oper == "top") {
			if (st.size() > 0) {
				cout << st.top() << "\n";
			}
			else
				cout << "-1\n";
		}
		else if (oper == "size") {
			cout << st.size() << '\n';
		}
		else if (oper == "empty") {
			cout << st.empty() << '\n';
		}
	}

}
