#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct Car
{
    int x,y,dir,dist;
};

bool visited[30][30];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int solution(vector<vector<int>> board) {
    int answer = 987654321;
    int n = board.size();

    Car c = {0,0,-1,0};
    queue<Car> q;
    q.push(c);
    board[0][0] = 1;

    while(!q.empty()) {
        Car c = q.front();
        q.pop();


        if (c.x == n-1 && c.y == n-1) {
            answer = min(answer, c.dist);
            continue;
        }

        int nx, ny;
        for (int i = 0; i < 4; ++i) {
            nx = dx[i] + c.x;
            ny = dy[i] + c.y;

            if (nx < 0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] == 1) {
                continue;
            }

            int dist = c.dist + 100;
            if (c.dir != i && c.dir != -1) {
                dist += 500;
            } 

            // board[nx][ny] < dist 라면 출발점에 더 가까워지므로 패스하는 것
            if (board[nx][ny] == 0 || board[nx][ny] >= dist) {
                board[nx][ny] = dist;
                Car nc = {nx, ny, i, dist};
                q.push(nc);
                //cout << nx  <<","<< ny << "," << i << "," << dist << endl;
            }


        }
    }
    
    return answer;
}