#include <algorithm>
#include <vector>

using namespace std;

int dp[101][1000001];
int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    
    dp[0][travel[0][0]] = travel[0][1];
    dp[0][travel[0][2]] = travel[0][3];
    
    for (int i = 1; i < travel.size(); i++) {  
        for (int j = 1; j <= K; j++) {
            if (dp[i-1][j] != 0) {
                // 도보
                if (dp[i][travel[i][0]] + j <= K) {
                    dp[i][travel[i][0]+j] = max(dp[i][travel[i][0]+j], dp[i-1][j] + travel[i][1]);
                } 
                // 자전거
                if (dp[i][travel[i][2]] + j <= K) {
                    dp[i][travel[i][2]+j] = max(dp[i][travel[i][2]+j], dp[i-1][j] + travel[i][3]);
                }
            }
        }      
    }
    
    for (int i = 1; i <= K; i++) {
        if (dp[travel.size()-1][i] != 0) {
            answer = max(answer, dp[travel.size()-1][i]);
        }
    } 
    
    return answer;
}