#include <string>
#include <vector>

using namespace std;

vector<int> answer;
bool visited[21];

void dfs(int idx, int cnt, int n, int k) {
	if (cnt == n && cnt == k) {
		for (int i = 0; i < count; ++i) {
			answer.push()
		}
		return;
	}

    for (int i = 1; i <= n; i++) {
    	if (visited[i]) continue;
    	visited[i] = true;
    	dfs()
    }
}

vector<int> solution(int n, long long k) {
    long long p = 1;
    for (int i = 2; i < n; i++) {
    	p *= i;
    }

    for (int i = 1; i <= n; i++) {
    	if (k >= (i-1)*p+1 && k <= i*p) {
    		answer.push_back(i);
    		dfs(i, i*p, int n, k-(i*p));
    	}
    }

    return answer;
}