#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
   	long long sum = 0;
    
    priority_queue<int> pq;

    for (int i = 0; i < works.size(); i++) {
    	sum += works[i];
    	pq.push(works[i]);
    }

    if (sum <= n) return 0;

    while(!pq.empty() && n > 0){
        int top = pq.top();
        pq.pop();

        if (top - pq.top() >= n) {
        	top -= n;
        	pq.push(top);
        	break;
        } 

        pq.push(top-1); 
        n--;     
    }

    while(!pq.empty()) {
    	answer += pq.top() * pq.top();
    	pq.pop();
    }
    
    return answer;
}