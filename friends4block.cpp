#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool visited[31][31];
int solution(int m, int n, vector<string> board) {
    int answer = 0;

    bool flag = false;

    while(!flag) {
      if (flag) break;
      flag = true;
      //vector<vector<bool>> visited(m, vector<bool>(n));
      for (int i = 0; i < m-1; ++i) {
        for (int j = 0; j < n-1; ++j) {
          char f = board[i][j];
          if (f == 'X') continue;

          if (f == board[i][j+1] && f == board[i+1][j] && f == board[i+1][j+1]) {
            visited[i][j] = true;
            visited[i][j+1] = true;
            visited[i+1][j] = true;
            visited[i+1][j+1] = true;
            flag = false;
          }
        }
      }

      if (!flag) {
        for (int i = 0; i < m; ++i) {
          for (int j = 0; j < n; ++j) {
            if (visited[i][j]) {
              answer++;
              board[i][j] = 'X';
              for (int k = i-1; k >= 0; k--) {
                swap(board[k][j],board[k+1][j]);
              }
              visited[i][j] = false;
            }
          }
        }
      }

      /*for (int i = 0; i < m; ++i) {
        cout << board[i] << endl;
      }

      cout << endl;*/

      
    }
    
    return answer;
}