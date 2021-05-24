#include<vector>
#include<queue>
#include<iostream>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool visited[101][101];
int n,m;

int solution(vector<vector<int> > maps)
{
    n = maps.size();
    m = maps[0].size();
    int answer = 987654321;
        
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},1});
    visited[0][0] = true;
    
    while(!q.empty()) {
        pair<int,int> dir = q.front().first;
        int x = dir.first;
        int y = dir.second;
        int cnt = q.front().second;
        
        q.pop();
        
        if (x == n-1 && y == m-1) {
            if (answer > cnt) {
                answer = cnt;
            }
            continue;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            
            if (!visited[nx][ny] && maps[nx][ny] == 1)  {
                visited[nx][ny] = true;
                q.push({{nx,ny},cnt+1});
                //cout << "?";
            }
        }
        
    }
    
    if (answer == 987654321) return -1;
    return answer;
}