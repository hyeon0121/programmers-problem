#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> v;
    map<string,int> m;
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < alpha.size(); ++i) {
        string s;
    	m[s+alpha[i]] = alpha[i] - 'A' +1 ;
    }
    

    int di = 0;

    for (int i = 0; i < msg.size(); ++i) {
    	string w;
    	w += msg[i];

    	int cnt = 0;
    	int idx = i;

    	while (m.find(w) != m.end()) {
    		idx++;
    		w += msg[idx];
    	}
    
    	m[w] = 27 + di;
    	di++;

    	w.pop_back();
    	answer.push_back(m[w]);

    	i = idx-1;
    		
    }
    return answer;
}