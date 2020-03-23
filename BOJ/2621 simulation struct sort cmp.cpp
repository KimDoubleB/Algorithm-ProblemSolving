#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#define debug false
#define bb ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
struct card {
	int num;
	int color;
};
struct countcard {
	int count;
	int num;
};
countcard same[10];
vector<card> vec;

bool cmp1(const card& c1, const card& c2) {
	if (c1.num < c2.num) return true;
	else return false;
}
bool cmp2(const countcard& c1, const countcard& c2) {
	if (c1.count > c2.count) return true;
	else if (c1.count == c2.count) return c1.num > c2.num;
	else return false;
}

bool sameColor() {
	int c = vec[0].color;
	for (int i = 1; i < 5; ++i) {
		if (c != vec[i].color) return false;
	}
	return true;
}

bool contiNum() {
	int snum = vec[0].num + 1;
	for (int i = 1; i < 5; ++i, ++snum) {
		if (snum != vec[i].num) return false;
	}
	return true;
}

void sameNum() {
	int index;
	for (int i = 0; i < 5; ++i) {
		index = vec[i].num;
		same[index].count++;
		same[index].num = index;
	}
	sort(same, same + 10, cmp2);
}

int main() {
	bb;
	int i = 5, n, ans;
	char c;
	// input
	while (i--) {
		cin >> c >> n;
		vec.push_back({ n, c });
	}
	sort(vec.begin(), vec.end(), cmp1);
	bool sameC = sameColor();
	bool contiN = contiNum();
	sameNum();

	// debug
	if (debug) {
		cout << same << '\n';
		for (int i = 0; i < 9; ++i) {
			cout << same[i].num << ' ' << same[i].count << '\n';
		}
		cout << "All same: " << sameC << '\n';
		cout << "Continuous: " << contiN << '\n';
	}

	if (sameC && contiN) {
		ans = vec[4].num + 900;
	}
	else if (same[0].count == 4) {
		ans = same[0].num + 800;
	}
	else if (same[0].count == 3 && same[1].count == 2) {
		ans = (same[0].num * 10) + same[1].num + 700;
	}
	else if (sameC) {
		ans = vec[4].num + 600;
	}
	else if (contiN) {
		ans = vec[4].num + 500;
	}
	else if (same[0].count == 3) {
		ans = same[0].num + 400;
	}
	else if (same[0].count == 2 && same[1].count == 2) {
		ans = (same[0].num * 10) + same[1].num + 300;
	}
	else if (same[0].count == 2) {
		ans = same[0].num + 200;
	}
	else {
		ans = vec[4].num + 100;
	}
	cout << ans << '\n';
}
