#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int cnt[21];
map<string,int> m;
vector<string> res;
void comb(int idx, string order, string s, int size) {
	if (s.size() == size) {
		m[s]++;

		if (cnt[size] < m[s]) {
			cnt[size] = m[s];
		}

		return;
	}
	for (int i = idx; i < order.size(); ++i) {
		s.push_back(order[i]);
		comb(i+1, order, s, size);
		s.pop_back();
	}

}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (int i = 0; i < orders.size(); ++i) {
    	string order = orders[i];
    	sort(order.begin(), order.end());

    	for (int j = 0; j < course.size(); ++j)
    	{
    		if (course[j] <= order.size()) {
    			comb(0, order, "", course[j]);
    		}
    		
    	}
    	
    }

    for (auto i = m.begin(); i != m.end(); i++){
    	string menu = i->first; 
    	if (cnt[menu.size()] >= 2 && i->second == cnt[menu.size()]) {
    		answer.push_back(menu);
    	}
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}