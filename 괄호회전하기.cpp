#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <stack>

using namespace std;

int solution(string s) {
	map<char,char> m;

	m['('] = ')';
	m['{'] = '}';
	m['['] = ']';

    int answer = 0;
    
    int n = s.size();
    if (n%2 != 0) return 0;
    
    int idx = -1;

    for (int idx = 0; idx < s.size(); ++idx) {
    	if (s[idx] == '(' || s[idx] == '{' || s[idx] == '[') {
    		string res = s.substr(idx) + s.substr(0,idx);

		    stack<char> next;
		    next.push(m[res[0]]);
		    bool flag = true;

		    for (int i = 1; i < res.size(); ++i) {
		    	if (res[i] == '(' || res[i] == '{' || res[i] == '[') {
		    		next.push(m[res[i]]);
		    	} else {
		    		if (next.empty()) {
		    			flag = false;
		    			break;
		    		}

		    		if (res[i] == next.top()) {
		    			next.pop();
		    		} else {
		    			flag = false;
		    			break;
		    		}
		    	}
		    }

		    if (flag && next.empty()) answer++;
    	}
    }
    
    //cout << res;
    return answer;
    
    
}