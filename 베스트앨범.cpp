#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
 	map<string, int> tmp;

    for (int i = 0; i < genres.size(); i++) {
    	tmp[genres[i]] += plays[i];
    }

   	vector<pair<string, int>> tmp2;
   
    for (auto i = tmp.begin(); i != tmp.end(); i++) {
        //cout << i->first << i->second << endl;
    	tmp2.push_back(make_pair(i->first,i->second));
    }

    sort(tmp2.begin(), tmp2.end(), cmp);

    for (auto i = tmp2.begin(); i != tmp2.end(); i++) {
  		int first = 0;
  		int second = 0;
  		int idx1 = -1;
  		int idx2 = -1;
    	string g = i->first;

    	for (int j = 0; j < genres.size(); j++) {
    		if (g.compare(genres[j]) == 0) {
    			if (plays[j] > first) {
    				second = first;
    				first = plays[j];
                    idx2 = idx1; 
    				idx1 = j;
                    
                    //cout << j << idx1 << endl;

    			} else if (plays[j] == first || plays[j] > second) {
    				second = plays[j];
    				idx2 = j;
    			} 
    		}
    	}
    	
    	answer.push_back(idx1);
    	if (idx2 != -1) {
    		answer.push_back(idx2);
    	}

    }

    return answer;
}