#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(int start, vector<vector<int>> v) {
	check[start]= true;
	printf("%d ", start);

	for(int i=0; i < graph[start].size(); i++){
		int next = graph[start][i];
		// 방문하지 않았다면
		if(check[next]==false){
			// 재귀함수를 호출한다.
			dfs(next, graph, check);
		}
	}
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<int> answer(2);

    queue<pair<int, int>> q;
    
    for (int i = 0; i < picture.size(); i++) {
    	for (int j = 0; j < picture[i].size(); j++) {
    		if (picture[i][j] != 0) {
    			q.push(make_pair(i,j));
    		}
    		
    	}
    }

    map<int,int, greater<int>> map;

    while(!q.empty()) {
    	int x = q.front().second; 
    	int y = q.front().first;
    	q.pop();

    	int prev = picture[y][x];

    	int tmpX = q.front().second;
    	int tmpY = q.front().first;

    	for (int i = 0; i < 4; i++) {
    		int nextY = y + dir[i][y];
			int nextX = x + dir[i][x];

    		if (nextX == tmpX && nextY == tmpY && prev == picture[tmpY][tmpX]) {
    			if (map[prev] < 1) {
    				map[prev] = 1;
    				/* code */
    			} else {
    				map[prev] += 1;
    			}
    			
    		}
    		
    	}
    }
    
    for (auto i = map.begin(); i != map.end() ; i++)
    {
    	cout << i->first << i->second << endl;
    }

    //sort(map.begin(), map.end(), cmp);

    answer[0] = map.begin()->second;
    answer[1] = map.size();

    return answer;
}

