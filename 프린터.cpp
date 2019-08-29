#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int cnt = 0;

    queue<pair<int, int>> q;
	priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); i++) {
    	q.push(make_pair(i, priorities[i]));
    	pq.push(priorities[i]);

    }

    while(!q.empty()) {
		pair<int, int> top = q.front();
    	
    	if (top.second == pq.front()) {
    		if (top.first == location) {
    			return cnt++;
    		} else {
    			q.pop();
    			pq.pop();
    			cnt++;
    		}
    	} else {
    		q.pop();
    		q.push(top);
    		
    	}
	}

    return cnt;
}

int main(void) {
	vector<int> p = {2, 1, 3, 2};

	int idx;
	cin >> idx;

	cout << solution(p, idx);

	return 0;

}