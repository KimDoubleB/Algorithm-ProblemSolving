#include <iostream>
#include <cmath>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int N, S, num[21];
int main()
{
	bb;
    cin >> N >> S;
    for(int i = 0; i < N; ++i) 
        cin >> num[i];
    int res = 0, pnum = pow(2, N); // 또는 (1<<N) 으로 해도 된다. 2의 N승 표현

    // 각 자리마다 2진수로 표현.
    // 고로, 1 ~ (2^N - 1)까지 순회해야함.
    for(int i = 1; i < pnum; ++i){ 
        int tmp = i, sum = 0;
        for(int j = 0; j < N; ++j){
            // 2진수 변환법 생각 --> 똑같은 매커니즘
            if(tmp == 0) break; // tmp가 0이 되버리면 굳이 for loop 수행 필요 X
            if(tmp % 2 == 1) sum += num[j];
            tmp /= 2;
        }
        if(sum == S) ++res;        
    }
    cout << res << '\n';
	return 0;
}
