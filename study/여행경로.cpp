#include <vector>
#include <algorithm>

using namespace std;

bool dfs(string from, vector<vector<string>> &tickets, vector<bool> &visited, vector<string> &answer, int cnt) {
	answer.push_back(from);

	if (cnt == tickets.size()) {
		return true;
	}

	for (int i = 0; i < tickets.size(); ++i) {
    	if (tickets[i][0] == from && !visited[i]) {
    		visited[i] = true;
    		int flag = dfs(tickets[i][1], tickets, visited, answer, cnt+1);
    		if (flag) return true;
    		visited[i] = false;
    	}
    }

    answer.pop_back();
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
	vector<bool> visited(tickets.size(), false);
	vector<string> answer;
	sort(tickets.begin(), tickets.end());
	dfs("ICN", tickets, visited, answer, 0);

    return answer;
}