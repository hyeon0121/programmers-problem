#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < scoville.size(); i++) {
    	q.push(scoville[i]);
    }

    while (1) {
    	if (q.top() >= K || q.size() <= 1) {
    		break;
    	}
    	answer++;
    	int first = q.top();
    	q.pop();
    	int second = q.top();
    	q.pop();
    	q.push(first + (second * 2));
    }

    if (q.top() < K)
    {
    	return -1;
    }

    return answer;
}