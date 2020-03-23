#include <iostream>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;

void star(int i, int j, int three){
    // 3의 배수로 나눈 몫이 1이거나, 몫을 3으로 나눈 나머지가 3인 경우, 공백
    if((i/three)%3 == 1 && (j/three)%3 == 1)
        cout << ' ';
    else{
        if((three/3) == 0) cout << '*'; // base condition
        else star(i, j, three/3);
    }
}

int main()
{
	bb;
    int three;
    cin >> three;
    for(int i = 0; i < three; ++i){
        for(int j = 0; j < three; ++j){
            star(i, j, three);
        }
        cout << '\n';
    }
    return 0;
}