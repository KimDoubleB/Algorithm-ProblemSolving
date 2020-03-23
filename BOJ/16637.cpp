#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define ll long long 
using namespace std;
int n;
ll maxval = LLONG_MIN;
vector<int> num;
vector<char> oper;
ll calculator(ll p1, ll p2, char operation) {
	switch (operation) {
	case '+':
		return p1 + p2;
	case '*':
		return p1 * p2;
	case '-':
		return p1 - p2;
	}
}

void solution(ll val, int cnt) {
	if (cnt == n / 2) {
		if (val > maxval)
			maxval = val;
		return;
	}
	ll val2 = calculator(val, num[cnt + 1], oper[cnt]);
	solution(val2, cnt + 1);
	if (cnt + 2 <= n / 2) {
		val2 = calculator(num[cnt + 1], num[cnt + 2], oper[cnt + 1]);
		val2 = calculator(val, val2, oper[cnt]);
		solution(val2, cnt + 2);
	}
}

int main() {
	char c;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c;
		if (c >= '0' && c <= '9')
			num.push_back(c-'0');
		else
			oper.push_back(c);
	}
	solution(num[0], 0);
	cout << maxval << '\n';


	return 0;
}