#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    vector<pair<int,string>> g;

    for (int i = 0; i < genres.size(); i++) {
        if (m.find(genres[i]) == m.end()) {
            m[genres[i]] = plays[i];
        } else {
            m[genres[i]] += plays[i];
        }
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        g.push_back(make_pair((*it).second, (*it).first));
    }

    // 재생횟수로 정렬
    sort(g.begin(), g.end(), greater<pair<int,string>>());
    
    for (int i = 0; i < g.size(); i++) {
        int idx1 = 0;
        int idx2 = 0;
        int first = 0;
        int second = 0;
        
        for (int j = 0; j < genres.size(); j++) {
            if (g[i].second == genres[j]) {
                if (plays[j] > first) {
                    idx2 = idx1;
                    second = first;
                    idx1 = j;
                    first = plays[j];
                } else if (plays[j] > second) {
                    idx2 = j;
                    second = plays[j];
                }
            }       
        }
        
        if (first > 0) {
            answer.push_back(idx1);
            if (second > 0) {
                answer.push_back(idx2);
            }            
        }
    }
  
    return answer;
}