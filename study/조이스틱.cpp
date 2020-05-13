#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int visited[20] = {false,};

    for (int i = 0; i < name.length(); i++) {
    	if (name[i] == 'A') {
    		visited[i] = true;
    	} else {
    		if (name[i] - 'A' < 'A' - name[i]+26) {
    			answer += name[i] - 'A';
    		} else {
    			answer += 'A' - name[i]+26;
    		}
    	}
    }

    return answer;
}