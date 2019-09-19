#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    bool flag = true;
    int cnt = 0;

    for (int i = 0; i < skill_trees.size(); ++i) {
    	for (int j = 0; j < skill_trees[i].size(); ++j) {
    		
    		int temp = skill.find(skill_trees[i][j]);

    		if (temp < 0) {
    			continue; 

    		} else if (temp != cnt) {
    			flag = false;
    			break;

    		} else {
    			cnt++;
    		}

    		cout << temp << endl;
    		
    	}

    	if(flag) {
    		answer++;
    	}

    	flag = true;
    	cnt = 0;
    }

    return answer;
}