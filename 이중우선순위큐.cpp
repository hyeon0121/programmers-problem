#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer = {0, 0};
    deque<int> dq;
    for (int i = 0; i < operations.size(); i++) {
        string opr = operations[i];
        int num = stoi(opr.substr(2));
        
        if (opr[0] == 'I') {
            dq.push_back(num);
            sort(dq.begin(), dq.end());
        } else {          
            if (num == 1) {
                if (!dq.empty()) {
                    dq.pop_back();
                }
                
            } else {
                if (!dq.empty()) {
                    dq.pop_front();
                }
            }
        }
        
    }
    
    answer[0] = dq.empty() ? 0 : dq.back();
    answer[1] = dq.empty() ? 0 : dq.front();
    
    return answer;
}