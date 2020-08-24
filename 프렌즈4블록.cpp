#include <string>
#include <vector>

using namespace std;

int getScore(int m, int n, vector<string> board) {
	for (int i = 0; i < m-1; ++i) {
		for (int j = 0; j < n-1; ++j) {
			char val = board[i][j];
			if (val == board[i][j+1] && val == board[i+1][j] 
			&& val == board[i+1][j+1]) {
				board[i][j] = 'X';
			}
		}
		/* code */
	}
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while(1) {
    	int score = getScore(m, n, board);
    	if (score == 0) break;

    	answer += score;
    }

    return answer;
}