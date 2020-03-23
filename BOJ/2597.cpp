#include <iostream>
// 문제 출력조건 잘보자.
// 소숫점 한자리까지 출력.
// 이걸로 1시간 날렸네....

using namespace std;
struct colorpt {
	int x1, x2;
	bool overlap;
};
colorpt pt[3];
double length = 0, lstart = 0, lend, middle;

bool allOverlap() {
	bool all = true;
	middle = -1;
	for (int i = 0; i < 3; ++i) {
		if (!pt[i].overlap) {
			if (middle < 0 || middle == ((pt[i].x1 + pt[i].x2) / 2.0)) {
				middle = (pt[i].x1 + pt[i].x2) / 2.0;
				pt[i].overlap = true;
				all = false;
			}
		}
	}
	return all;
}

int mirror(int& val, int& center) {
	return center + center - val;
}
int main() {
	scanf("%lf", &lend);
	for (int i = 0; i < 3; ++i)
		scanf("%d %d", &pt[i].x1, &pt[i].x2);
	
	while (!allOverlap()) {
		for (int i = 0; i < 3; ++i) {
			if (!pt[i].overlap) {
				if (middle > pt[i].x1)
					pt[i].x1 = (2 * middle) - pt[i].x1;
				if (middle > pt[i].x2)
					pt[i].x2 = (2 * middle) - pt[i].x2;
			}
		}
		if (lend < (2 * middle) - lstart)
			lend = (2 * middle) - lstart;
		lstart = middle;	
		length = lend - lstart;

	}

	printf("%.1f", length);
	return 0;
}