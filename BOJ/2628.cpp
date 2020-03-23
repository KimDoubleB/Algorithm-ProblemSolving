#include <iostream>
#include <vector>
#include <algorithm>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);
using namespace std;

int solution(vector<int>& line) {
	int len = 0;
	for (int i = 1; i < line.size(); ++i)
		len = max(len, (line[i] - line[i - 1]));
	return len;
}

int main() {
	bb;
	int w, h, num_line, wh, sep;
	int wmax, hmax;
	cin >> w >> h >> num_line;
	vector<int> wline, hline;
	wline.push_back(0); wline.push_back(w);
	hline.push_back(0); hline.push_back(h);
	for (int i = 0; i < num_line; ++i) {
		// 1 --> 세로 --> 가로 자름
		// 0 --> 가로 --> 세로 자름
		cin >> wh >> sep;
		if (wh) wline.push_back(sep);
		else hline.push_back(sep);
	}

	// sort
	sort(wline.begin(), wline.end());
	sort(hline.begin(), hline.end());

	wmax = solution(wline);
	hmax = solution(hline);

	cout << wmax * hmax << '\n';
	return 0;
}