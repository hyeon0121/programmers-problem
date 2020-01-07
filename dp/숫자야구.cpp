#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;

    vector<int> v;

    for (int i = 123; i <= 987; i++) {
    	string tmp = to_string(i);
    	if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2])
			continue;
		else if (tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0')
			continue;

		bool flag = true;

    	for (int j = 0; j < baseball.size(); j++) {
    		string num = to_string(baseball[j][0]);
	    	int s = 0;
	    	int b = 0;

	    	for (int x = 0; x < 3; x++) {
	    		for (int y = 0; y < 3; y++) {
	    			if (x == y && tmp[x] == num[y]) {
	    				s++;
	    				continue;
	    			}

	    			if (x != y && tmp[x] == num[y]) {
	    				b++;
	    				continue;
	    			}
	    		}
	    	}

	    	if (s != baseball[j][1] || b != baseball[j][2]) {
	    		flag = false;
	    		break;
	    	}
    	}

    	if (flag) {
    		answer++;
    	}
    	
    }

    return answer;
}