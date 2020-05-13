#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); i++) {
        string s = skill_trees[i];
        int idx = 0;
        bool flag = true;

        for (int j = 0; j < s.size(); j++) {
            for (int k = 0; k < skill.size(); k++) {
                if (s[j] == skill[k]) {
                    if (idx == k) idx++;
                    else {
                        flag = false;
                        break;
                    }
                }
            }
            
            if (!flag) break;
        }
        
        if (flag) answer++;
    }
    
    return answer;
}