#include <queue>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cmp(pair<double,int> a, pair<double,int> b) {
    if (a.first == b.first) 
        return a.second < b.second;

    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    int users[501] = {0};
    int total = stages.size();

    vector<pair<double, int>> v;
    for (int i = 0; i < stages.size(); i++) {
        users[stages[i]-1]++;
    }

    for (int i = 0; i < N; i++) {
        if (users[i] == 0) {
            v.push_back(make_pair(0, i+1));
        } else {
            v.push_back(make_pair((double)users[i]/total, i+1));
            total -= users[i];
        }

    }
    
    sort(v.begin(), v.end(), cmp);

    for (auto i = v.begin(); i != v.end(); i++) {
        answer.push_back(i->second);
    }
    
    return answer;
}