#include <iostream>
#include <string>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);
using namespace std;
string c[11];
const string lang_ind[8] = { "A", "B", "C", "D", "E", "F", "G", "H" };
const string lang[8] = { "000000", "001111", "010011", "011100",
						"100110","101001","110101", "111010"};

int differ(string& str1, int& j) {
	int d = 0;
	for (int k = 0; k < 6; ++k)
		if (str1[k] != lang[j][k])
			d++;
	return d;
}
int main() {
	bb;
	int n, diff;
	cin >> n;
	string secret, res = "";
	cin >> secret;
	for (int i = 0; i < n*6; i = i + 6)
		c[i / 6] = secret.substr(i, 6);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 8; ++j) {
			diff = differ(c[i], j);
			if (diff < 2) {
				res += lang_ind[j];
				break;
			}
		}
		if (res.size() != i+1) {
			res = (i+1+'0');
			break;
		}
	}
	cout << res << '\n';
	return 0;
}