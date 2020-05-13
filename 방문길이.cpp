#include <string>
#include <iostream>

using namespace std;

bool visited[11][11][11][11];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int dir(char ch) {
    if (ch == 'U') return 0;
    if (ch == 'D') return 1;
    if (ch == 'R') return 2;
    if (ch == 'L') return 3;
}
int solution(string dirs) {    
    int x = 5;
    int y = 5;
    int answer = 0;
    
    for (int i = 0; i < dirs.size(); i++) {
        int d = dir(dirs[i]);
        int nx = x + dx[d];
        int ny = y + dy[d];
                        
        if (nx < 0 || ny < 0 || nx >= 11 || ny >= 11) continue;  
        
        if (!visited[x][y][nx][ny]) {
            visited[x][y][nx][ny] = true;
            visited[nx][ny][x][y] = true;
            answer++;
        }
        
        x = nx;
        y = ny;
    }
        
	return answer;
}