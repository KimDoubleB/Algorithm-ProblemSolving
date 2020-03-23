#include <iostream>
#include <vector>
#define bb ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL);
using namespace std;
const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
const char connect[SWITCHES][CLOCKS+1] = {
    "---0000000000000",
    "000-000-0-0-0000",
    "0000-00000-000--",
    "-000----00000000",
    "000000---0-0-000",
    "-0-00000000000--",
    "000-0000000000--",
    "0000--0-000000--",
    "0-----0000000000",
    "000---000-000-00"
};
bool isAllTwelve(vector<int>& clocks){
    for(int clock = 0; clock < CLOCKS; ++clock)
        if(clocks[clock] != 12) return false;
    return true;
}
void push(vector<int>& clocks, int swtch){
    for(int clock = 0; clock < CLOCKS; ++clock){
        if(connect[swtch][clock] == '-'){
            clocks[clock] += 3;
            if(clocks[clock] == 15) clocks[clock] = 3;
        }
    }
}
int make_twelve(vector<int>& clocks, int swtch){
    if(swtch == SWITCHES) return isAllTwelve(clocks) ? 0 : INF;
    
    // Switch 3번 누르는 것까지 다 수행
    int ret = INF;
    for(int cnt = 0; cnt < 4; ++cnt){
        ret = min(ret, cnt + make_twelve(clocks, swtch + 1));
        push(clocks, swtch);
    }

    return ret;
}


int main()
{
    bb;
    int t;
    cin >> t;
    for(int tt = 0; tt < t; ++tt){
        vector<int> clocks;
        int tmp, result;
        for(int i = 0; i < CLOCKS; ++i){
            cin >> tmp;
            clocks.push_back(tmp);
        }
        result = make_twelve(clocks, 0);
        if(result >= INF) result = -1;
        cout << result << '\n';
    }    
    return 0;
}