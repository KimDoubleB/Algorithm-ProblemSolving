#include <vector>
void printPicked(vector<int> picked);


// n 중에 m개를 고르는 모든 조합을 찾는 알고리즘
/*
n: 전체 원소의 수
picked: 지금까지 고른 원소들의 번호
toPick: 더 고를 원소의 수 (0이 될 때까지) 
*/

// 앞으로 toPick 개의 원소를 고르는 모든 방법을 출력
void pick(int n, vector<int>& picked, int toPick){
    // base condition: 더 고를 원소가 없으면, 고른 원소들을 출력한다.
    if(toPick == 0) { printPicked(picked); return; }

    int smallest = picked.empty() ? 0 : picked.back() + 1;
    for(int next = smallest; next < n; ++next){
        // 추가해서 재귀로 주고, for 문으로 돌면서 추가 안한경우를 생각해 다시 빼준다.
        picked.push_back(next);
        pick(n, picked, toPick-1);
        picked.pop_back();
    }


}