#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		arr[i][j] = 98765432;
    	}
    }

    for (int i = 1; i <= n; ++i) {
    	arr[i][i] = 0;
    }

    for (int i = 0; i < fares.size(); ++i) {
    	arr[fares[i][0]][fares[i][1]] = fares[i][2];
    	arr[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    // 플로이드 와샬
    for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= n; k++) {
				arr[j][k] = min(arr[j][k], arr[j][i]+arr[i][k]);
			}
		}
    }

    /*for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		cout << arr[i][j] << ' ';
    	}
    	cout << '\n';
    }*/

    int answer = 987654321;
    for (int i = 1; i <= n; ++i) {
    	answer = min(answer, arr[s][i]+arr[i][a]+arr[i][b]);
    	//cout << arr[s][i] << ' ' << arr[i][a] << ' ' << arr[i][b] << endl;

    }



    return answer;
}