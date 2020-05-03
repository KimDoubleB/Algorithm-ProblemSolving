#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
	vector<int> answer, tmp;
	answer.push_back(0);
	if (n == 1) return answer;
	for (int i = 2; i <= n; ++i) {
		tmp = answer;
		answer.push_back(0);
		for (int j = tmp.size() - 1; j >= 0; --j)
			answer.push_back((tmp[j] + 1) % 2);
	}


	return answer;
}