#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
 
	int cnt = 0;
    int sum = 0;

    for (int i = 0; i < truck_weights.size(); i++) {
    	int top = truck_weights[i];

		while(true) {

		    if (bridge.empty()) {
		    	bridge.push(top);
		    	sum += top;
		    	cnt++;
		    	break;

		    } else if (bridge.size() == bridge_length) {
		    	sum -= bridge.front();
		    	bridge.pop();

		    } else {
		    	if (sum + top > truck_weights) {
		    		bridge.push(0);
		    		cnt++;

		    	} else {
		    		bridge.push(top);
		    		sum += top;
		    		cnt++;
		    		break;
		    	}
		    }
		}

    }

    return cnt + bridge_length;
}

int main(void) {
	vector<int> v = {7, 4, 5, 6};
	int length = 2;
	int w = 10;

	cout << solution(length, w, v);

	return 0;
}