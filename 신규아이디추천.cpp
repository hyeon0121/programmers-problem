#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string tmp;
    for (int i = 0; i < new_id.size(); ++i) {
    	if (new_id[i] >= 'A' && new_id[i] <= 'Z') {
            tmp += tolower(new_id[i]);
        } else if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9')
              || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
            tmp += new_id[i];
        }
    }

    for (int i = 0; i < tmp.size(); ++i) {
    	if (tmp[i] == '.') {
    		answer += '.';

    		int cnt = 0;
    		for (int j = i; j < tmp.size(); ++j) {
	    		if (tmp[j] == '.') cnt++;
	    		else break;
	    	}

	    	if (cnt > 0) {
	    		i += cnt-1;
	    		continue;
	    	}

    	}

    	answer += tmp[i];
    }

    if (answer.front() == '.') answer.erase(answer.begin());
    if (answer.back() == '.') answer.pop_back();

    if (answer.size() == 0) answer = "a";

    if (answer.size() >= 16) {
    	answer = answer.substr(0,15);
    	if (answer.back() == '.') answer.pop_back();
    }

    if (answer.size() <= 2) {
    	char ch = answer.back();
    	while(answer.size() < 3) {
    		answer += ch;
    	}
    }

    return answer;
}