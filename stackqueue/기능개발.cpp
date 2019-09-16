#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> q;

    for (int i = 0; i < progresses.size(); i++) {
    	int cnt = 0;

    	while(true) {
    		if (progresses[i] < 100) {
    			progresses[i] += speeds[i];
    			cnt++;
    		} else {
    			q.push(cnt);
    			break;
    		}
    	}
    	
    }

    int tmp = 1;
    int top = q.front();
    q.pop();

    while(!q.empty()) { 

    	if (q.front() > top) {
    		answer.push_back(tmp);
            // cout << tmp << endl;
    		top = q.front();
    		tmp = 1;
    		q.pop();
    		
    	} else {
    		tmp++;
    		q.pop();
    	}
    } 
    
    answer.push_back(tmp);

    return answer;
}

int main(void) {
	vector<int> p = {93, 30, 55};
	vector<int> s = {1, 30, 5};

	vector<int> res = solution(p, s);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

	return 0;
}