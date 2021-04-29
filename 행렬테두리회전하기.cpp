#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[101][101];
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    int num = 1;
    for (int i = 1; i <= rows; ++i) {
    	for (int j = 1; j <= columns; ++j) {
    		arr[i][j] = num;
    		num++;
    	}
    }

    for (int i = 0; i < queries.size(); ++i) {
    	int x1 = queries[i][0];
    	int y1 = queries[i][1];
    	int x2 = queries[i][2];
    	int y2 = queries[i][3];

    	int x = x2-x1;
    	int y = y2-y1;

    	int nx = x1;
    	int ny = y1;
    	int now = arr[nx][ny];
    	int tmp;
    	int res = now;

    	// 왼>오
    	for (int j = 0; j < y; ++j) {
    		ny++;
    		tmp = arr[nx][ny];
    		res = min(res, tmp);
    		arr[nx][ny] = now;
    		now = tmp;
    	}

    	// 위>아래
    	for (int j = 0; j < x; ++j) {
    		nx++;
    		tmp = arr[nx][ny];
    		res = min(res, tmp);
    		arr[nx][ny] = now;
    		now = tmp;
    	}

    	// 오->왼
    	for (int j = 0; j < y; ++j) {
    		ny--;
    		tmp = arr[nx][ny];
    		res = min(res, tmp);
    		arr[nx][ny] = now;
    		now = tmp;
    	}

    	// 아래>위
    	for (int j = 0; j < x; ++j) {
    		nx--;
    		tmp = arr[nx][ny];
    		res = min(res, tmp);
    		arr[nx][ny] = now;
    		now = tmp;
    	}

    	/*for (int j = 1; j <= rows; ++j) {
	    	for (int k = 1; k <= columns; ++k) {
	    		cout << arr[j][k] << " ";
	    	}
	    	cout << endl;
	    }*/

    	//cout << res << endl;
    	answer.push_back(res);

    }
    return answer;
}