#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
vector<int> answer;

void pushpush(const int& n1, const int& n2){
    answer.push_back(n1);
    answer.push_back(n2);
}

vector<int> solution(int n, vector<string> words) {
    set<string> s;
    char before = words[0].at(0);
    for(int i = 0; i < words.size(); ++i){
        if(s.count(words[i]) > 0 || words[i].at(0) != before){
            // 중복 OR 끝말잇기 실패
            pushpush(i % n + 1, ceil((i+1)/(double)n));
            return answer;
        }
        s.insert(words[i]);
        before = words[i].at(words[i].size()-1);
    }
    pushpush(0, 0);
    return answer;
}