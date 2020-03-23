#include <bits/stdc++.h>
#define bb ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int arr[20];
int main() {
	bb;
	stack<char> st;
	string str;
	int i;
	cin >> str;
	for (i = 0; i < str.size(); ++i) {
		if (str[i] == '(' && str[i + 1] == ')') {
			arr[st.size()] += 2;
			++i;
		}
		else if (str[i] == '[' && str[i + 1] == ']') {
			arr[st.size()] += 3;
			++i;
		}
		else if (str[i] == '(' || str[i] == '[') {
			st.push(str[i]);
		}
		else if (str[i] == ')') {
			if (st.size() == 0 || st.top() != '(') break;
			int tmp = 2;
			arr[st.size() - 1] += (arr[st.size()] * tmp);
			arr[st.size()] = 0;
			st.pop();
		}
		else if (str[i] == ']') {
			if (st.size() == 0 || st.top() != '[') break;
			int tmp = 3;
			arr[st.size() - 1] += (arr[st.size()] * tmp);
			arr[st.size()] = 0;
			st.pop();
		}
	}
	if (i < str.size() || st.size() > 0) cout << 0 << '\n';
	else cout << arr[0] << '\n';
}