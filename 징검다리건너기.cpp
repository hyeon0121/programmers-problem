#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 987654321;
    deque<int> dq;

    for (int i = 0; i < stones.size(); ++i){
        if (!dq.empty() && dq.front() < i-k+1) {
            dq.pop_front();
        }

        while (!dq.empty() && stones[dq.back()] < stones[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
        //cout << stones[dq.front()] << ' ';
        
        if (!dq.empty() && i >= k-1) {
            if (answer > stones[dq.front()]) {
                answer = stones[dq.front()];
            }
        }

    }
    
    return answer;
}