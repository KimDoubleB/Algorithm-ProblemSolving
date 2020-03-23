#include <iostream>
#include <algorithm>
#include <cstring>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
int k, s[14], permu[14];
int main()
{
	bb;
    while(true){
        cin >> k;
        if(k==0) break;
        memset(permu, 0, sizeof(permu));
        for(int i = 0; i < k; ++i){
            if(i < 6) permu[i] = 1;
            cin >> s[i];
        }
        do{
            for(int i = 0; i < k; ++i)
                if(permu[i])
                    cout << s[i] << ' ';
            cout << '\n';
        }while(prev_permutation(permu, permu+k));
        cout << '\n';
    }
	return 0;
}
