#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;

    vector<int> st;
    vector<int> et;

    for (int i = 0; i < lines.size(); ++i) {
    		
    	lines[i].pop_back();
    	string h, m, s, ms;

    	h = lines[i].substr(11,2);
    	m = lines[i].substr(14,2);
    	s = lines[i].substr(17,2);
    	ms = lines[i].substr(20,3);


    	int T, ih, im, is;

    	T = stof(lines[i].substr(24)) * 1000;  

    	ih = stoi(h) * 60 * 60 * 1000;
    	im = stoi(m) * 60 * 1000;
    	is = stoi(s) * 1000 + stoi(ms);

    	st.push_back(ih+im+is-T+1);
    	et.push_back(ih+im+is);

    	//cout << ih+im+is-T+1 << '|' << ih+im+is << endl;
    }

    for (int i = 0; i < lines.size(); ++i) {
    	int cnt = 0;
    	int end_time = et[0] + 1000;

    	for (int j = i; j < lines.size(); ++j) {
    		if (st[j] < end_time) cnt++;
    	}

    	if (answer < cnt) {
    		answer = cnt;
    	}
    }
    return answer;
}