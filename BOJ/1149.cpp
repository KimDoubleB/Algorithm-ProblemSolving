#include <iostream>
#include <algorithm>
#define SIZE 1001
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int rgb[SIZE][3], rgbmax[SIZE][3];
int main()
{
	bb;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
		if (i == 0){
			// 초기값 설정
			rgbmax[0][0] = rgb[0][0];
			rgbmax[0][1] = rgb[0][1];
			rgbmax[0][2] = rgb[0][2];
		}
		else {
			// 이전 R, G, B 값을 확인해서 겹치지 않는 것의 최소값으로 색칠(값 계산)
			rgbmax[i][0] = min(rgbmax[i - 1][1], rgbmax[i - 1][2]) + rgb[i][0]; // Red
			rgbmax[i][1] = min(rgbmax[i - 1][0], rgbmax[i - 1][2]) + rgb[i][1]; // Green
			rgbmax[i][2] = min(rgbmax[i - 1][0], rgbmax[i - 1][1]) + rgb[i][2]; // Blue
		}
	}
	// 마지막 값들 중 최소값 출력
	cout << min(min(rgbmax[n - 1][0], rgbmax[n - 1][1]), rgbmax[n - 1][2]) << '\n';
	return 0;
}
