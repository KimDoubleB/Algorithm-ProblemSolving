#include <bits/stdc++.h>
using namespace std;
stack <int> s;
string result;
int po;

void pop() {
	s.pop();
	result += "-\n";
}
void push(int num) {
	for (int i = 0; i < num; i++) {
		s.push(++po);
		result += "+\n";
	}
	pop();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int list;
	cin >> list;

	while (list--) {
		int now;
		cin >> now;

		if (po <= now) push(now - po);
		else {
			if (now == s.top()) pop();
			else {
				list = -2;
				break;
			}
		}
	}

	if (list < -1) cout << "NO\n";
	else cout << result;
}