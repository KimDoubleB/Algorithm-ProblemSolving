#include <iostream>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
void moving(int start, int end, int num_pan){
    if(num_pan == 1){
        cout << start << ' ' << end << '\n';
        return;
    }
    else{
        int temp = 6 - start - end;
        moving(start, temp, num_pan - 1);
        cout << start << ' ' << end << '\n';
        moving(temp, end, num_pan - 1);
    }
}
int main()
{
	bb;
    int num;
    cin >> num;
    cout << (1 << num) - 1 << '\n'; 
    moving(1, 3, num);
    return 0;
}