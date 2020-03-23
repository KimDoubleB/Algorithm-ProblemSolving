#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[26];
	fill(&arr[0], &arr[0] + 26, 0); // 초기화

	string str;
	cin >> str; // 알파벳 받기

	// 해당하는 알파벳 개수 증가
	for (int i = 0; i < str.length(); i++) {
		++arr[str[i] - 'a']; 
	}

	
	// 결과 출력
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}
}