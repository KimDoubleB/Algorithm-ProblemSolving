#include <iostream>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL)
using namespace std;
int s[100], num_s, st_s, tp;
int mnum, wnum;
void turn(int b) {
	if (s[b])
		s[b] = 0;
	else
		s[b] = 1;
}
void man() {
	cin >> mnum;
	int val = mnum, mul = 1;
	while (val <= num_s) {
		turn(val-1);
		++mul;
		val = mnum * mul;
	}
}
void woman() {
	cin >> wnum;
	wnum -= 1;
	turn(wnum);
	int add = 1;
	while ((wnum - add >= 0 && wnum + add < num_s) &&
		(s[wnum + add] == s[wnum - add])) {
		turn(wnum + add);
		turn(wnum - add);
		++add;
	}
}

int main()
{
	bb;
	cin >> num_s;
	for (int i = 0; i < num_s; ++i)
		cin >> s[i];
	cin >> st_s;
	for (int i = 0; i < st_s; ++i) {
		cin >> tp;
		if (tp == 1)
			man();
		else
			woman();
	}

	for (int i = 0; i < num_s; ++i) {
		cout << s[i];
		if (i % 20 == 19) cout << '\n';
		else cout << ' ';
	}
	
	return 0;
}