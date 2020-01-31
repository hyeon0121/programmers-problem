#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";

    for (int i = 0; i < s.length(); i++) {
    	if (s[i-1] == ' ' || i == 0) {
    		if ('a' <= s[i] && s[i] <= 'z') {
    			answer += toupper(s[i]);
    			continue;
    		} 
    	} else {
    		if ('A' <= s[i] && s[i] <= 'Z') {
    			answer += tolower(s[i]);
    			continue;
    		} 
    	}
    	
    	answer += s[i];
    }

    return answer;
}