#include <iostream>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int r, c, mat[2][2] = {{0, 1}, {2, 3}};

int Z(int init_r, int init_c, int n){
    if(n==0) return 0; // base condition
    int temp_r, temp_c;
    int half = 1<<(n-1);

    // Row 
    if(init_r + half > r) temp_r = 0;
    else {
        init_r += half;
        temp_r = 1;
    }

    // Column
    if(init_c + half > c) temp_c = 0;
    else {
        init_c += half;
        temp_c = 1;
    }

    // Recursive
    return Z(init_r, init_c, n-1) + mat[temp_r][temp_c] * half * half;
}

int main()
{
	bb;
    int n;
    cin >> n >> r >> c;
    cout << Z(0, 0, n) << '\n';
    return 0;
}