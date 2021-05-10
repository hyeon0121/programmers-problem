#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

char friends[8] = {'A','C','F','J','M','N','R','T'};
bool visited[8];
int answer;
void dfs(int cnt, string s, vector<string> data) {
	if (cnt == 8) {
		//cout << s;
		for (int i = 0; i < data.size(); ++i) {
			string d = data[i];

			char a = d[0];
			char b = d[2];
			char cond = d[3];
			int num = d[4] - '0';
            num++;

			int ai, bi;
			for (int j = 0; j < s.size(); ++j) {
				if (s[j] == a) ai = j;
				else if (s[j] == b) bi = j;
			}

			if (cond == '=') {
				if (abs(ai-bi) != num) {
					return;
				}
			} else if (cond == '>') {
				if (abs(ai-bi) <= num) {
					return;
				}
			} else if (cond == '<') {
				if (abs(ai-bi) >= num) {
					return;
				}
			}
		}

		answer++;
		return;
	}
	for (int i = 0; i < 8; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(cnt+1, s+friends[i], data);
			visited[i] = false;
		}
	}
}
int solution(int n, vector<string> data) {
	answer =  0;
    dfs(0,"",data);
    return answer;
}