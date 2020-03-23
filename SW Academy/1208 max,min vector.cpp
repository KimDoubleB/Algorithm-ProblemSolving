#include <iostream>
#include <algorithm>
#include <vector>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int main()
{
	bb;
	for (int t = 1; t < 11; ++t) {
		int dump;
		cin >> dump;
		vector<int> boxes;
		for (int box = 0; box < 100; ++box) {
			int data;
			cin >> data;
			boxes.push_back(data);
		}
		for(int i = 0; i < dump; ++i) {
			int& highest = *max_element(boxes.begin(), boxes.end());
			int& lowest = *min_element(boxes.begin(), boxes.end());
			if (highest - lowest == 0 || highest - lowest == 1) break;
			highest--; lowest++;
		}
		cout << '#' << t << ' ' << (*max_element(boxes.begin(), boxes.end()) - *min_element(boxes.begin(), boxes.end())) << '\n';
	}
}
