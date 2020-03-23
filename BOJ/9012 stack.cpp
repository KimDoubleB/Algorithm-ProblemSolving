#include <bits/stdc++.h>
#define bb ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int main() {
	bb;
	int num;
	cin >> num;
	while (num--) {
		stack<char> st;
		int isOk = 1;
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ')') {
				if (st.empty() || st.top() != '('){
					isOk = -1;
					break;
				}	
				else st.pop();
			}
			else st.push('(');
		}
		if (isOk < 0 || !st.empty()) cout << "NO\n";
		else cout << "YES\n";
	}
}