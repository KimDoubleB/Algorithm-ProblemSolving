#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

struct song {
	int num, numplay;
};

unordered_map<string, int> mapplay;
vector<pair<string, int>> vecplay;
unordered_map<string, vector<song>> info;
vector<song> tmp;

void mapToVec(unordered_map<string, int>& m, vector<pair<string, int>>& v){
    for(auto i = m.begin(); i != m.end(); ++i)
        v.push_back({i->first, i->second});
}

bool cmp(const pair<string, int>& v1, const pair<string, int>& v2){
    return v1.second > v2.second;
}

bool cmp2(const song& s1, const song& s2){
    if(s1.numplay == s2.numplay)
        return s1.num < s2.num;
    return s1.numplay > s2.numplay;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

    for(int i = 0; i < genres.size(); ++i){
        if(mapplay.find(genres[i]) != mapplay.end()){
            // 있다.
            mapplay[genres[i]] = mapplay[genres[i]] + plays[i];
        }else{
            // 없다.
            mapplay[genres[i]] = plays[i];
            info[genres[i]] = vector<song>();
        }
        info[genres[i]].push_back({i, plays[i]});
    }
    
    mapToVec(mapplay, vecplay);
    sort(vecplay.begin(), vecplay.end(), cmp);
    for(auto i = 0; i < vecplay.size(); ++i){
        tmp = info[vecplay[i].first];
        sort(tmp.begin(), tmp.end(), cmp2);
        int ind = 1;
        for(int j = 0; j < tmp.size(); ++j){
            answer.push_back(tmp[j].num);
            if(j == ind) break;
        }
    }
    
	return answer;
}