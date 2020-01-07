#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> q(works.begin(), works.end());
    
    for (int i = 0; i < n; i++) {
        if(q.top() > 0) {
            int top = q.top();
            q.pop();
            q.push(--top);
        } else {
            break;
        }
    }
    
    while(!q.empty()) {
        answer += (long long) (q.top() * q.top());
        q.pop();
    }
    return answer;
}