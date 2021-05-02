#include <string>
#include <vector>
#include <iostream>

using namespace std;

int map[5001][5001];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for (int i = 0; i < results.size(); i++) {
        map[results[i][0]][results[i][1]]++;
        map[results[i][1]][results[i][0]]--;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[j][i] == 0) continue;
            
            for (int k = 1; k <= n; k++) {
                if (map[j][i] == map[i][k]) {
                    map[j][k] = map[j][i];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
    
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        
        for (int j = 1; j <= n; j++) {
            if (map[i][j] != 0) cnt++;
        }
        
        if (cnt == n-1) answer++;
    }
    return answer;
}