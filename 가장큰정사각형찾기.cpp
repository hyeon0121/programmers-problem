#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    int h = board.size();
    int w = board[0].size();

    int max = 0;

    if (h < 2 || w < 2) {
    	for (int i = 0; i < h; i++) {
    		for (int j = 0; j < w; j++) {
    			if (board[i][j] == 1) {
    				max = 1;
    				break;
    			}
    		}
    	}
    } else {
    	for (int i = 1; i < h; i++) {
    		for (int j = 1; j < w; j++) {
    			if (board[i][j] == 1) {
    				int m = min({board[i-1][j], board[i][j-1], board[i-1][j-1]});
    				board[i][j] += m;
    				if (board[i][j] > max) max = board[i][j];
    			}
    		}
    	}
    }

    answer = max * max;  

    return answer;
}

int main(void) {
    vector<vector<int>> board{
        {0,1,1,1},
        {1,1,1,1},
        {1,1,1,1},
        {0,0,1,0}};

    cout << solution(board) << endl;
}