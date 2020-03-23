#include <iostream>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
bool isUsed[30], isUsed1[30], isUsed2[30];
int N, res;
void queen(int x){ // row 값 넘어옴
    if(x == N) ++res;
    else{
        for(int y = 0; y < N; ++y){ // col 값 순회
            // isUsed[y]: 현재 column 가능한가?
            // isUsed1[x+y]: / 방향 대각선이 가능한가?
            // isUsed2[x-y + N-1]: \ 방향 대각선이 가능한가?
            // >>>>  isUsed[x]는 안하는 것 >> 현재 row별로 함수에 들어온 것이기에 무조건 비어져있는 것.
            if(isUsed[y] || isUsed1[x+y] || isUsed2[x-y+N-1]) continue;
            isUsed[y] = isUsed1[x+y] = isUsed2[x-y+N-1] = true;
            queen(x+1);
            isUsed[y] = isUsed1[x+y] = isUsed2[x-y+N-1] = false;
        }
    }
}
int main()
{
	bb;
    cin >> N;
    queen(0);
    cout << res << '\n';
	return 0;
}
