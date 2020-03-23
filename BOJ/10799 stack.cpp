#include <bits/stdc++.h>
#define bb ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int bar[50000];

int main() {
	bb;

	stack<char> st;
	string str;
	int result=0;
	cin >> str;
	// bar[0] => 최종값 저장

	for (int i = 0; i < str.size();) {
		if (str[i] == ')') { // 끝
			bar[0] += (bar[st.size()] + 1);
			if (st.size() > 1) bar[st.size() - 1] += bar[st.size()];
			bar[st.size()] = 0;
			st.pop();
			i += 1;
		}
		else if (str[i] == '(' && str[i + 1] == ')') { // Laser
			if (st.size() > 0) bar[st.size()]++;
			i += 2;
			continue;
		}
		else if (str[i] == '(') { // 시작
			st.push('(');
			i += 1;
		}
	}
	cout << bar[0] << '\n';
}