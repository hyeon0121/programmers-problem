#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;

    stack<int> s;

    for (int i = heights.size()-1; i >= 0; i--) {
    	int check = 0;
    	for (int j = i - 1; j >= 0; j--) {
    		if (heights[i] < heights[j]) {
    			s.push(j+1);
    			check++;
    			break;
    		}
    	}

    	if (check == 0) {
    		s.push(0);
    	}
    	
    }

    while(!s.empty()) {
		answer.push_back(s.top());
		s.pop();
	}

    return answer;
}

int main(void) {
	vector<int> v = {6, 9, 5, 7, 4};

	vector<int> res = solution(v);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	
	return 0;
}