#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int parent[101];

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}
bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    int cnt = 0;

    sort(costs.begin(), costs.end(), cmp);
    
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < costs.size(); i++) {
        //if (cnt == n-1) break;
        int a = getParent(costs[i][0]);
        int b = getParent(costs[i][1]);
        if (a != b) {
            cout << cnt << ',' << costs[i][0] << ' ' << costs[i][1] << endl;
            parent[b] = a;
            answer += costs[i][2];
            cnt++;
            for (int j = 0; j < n; j++) {
                cout << parent[j] << ' ';
            }
            cout << endl;
        }
     } 
    
    return answer;
}