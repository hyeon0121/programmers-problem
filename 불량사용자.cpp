#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

bool chk[9];
int n;
vector<int> v[9];
set<string> answer;

void dfs(int idx, string s) {
    if (idx == n) {
        sort(s.begin(), s.end());
        answer.insert(s);
        return;

    }
    for (int i = 0; i < v[idx].size(); ++i) {
        int id = v[idx][i];
        if (!chk[id]) {

            chk[id] = true;
            dfs(idx+1, s + to_string(id));
            chk[id] = false;
        }

    }

}
int solution(vector<string> user_id, vector<string> banned_id) {
    n = banned_id.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < user_id.size(); ++j) {
            if (banned_id[i].size() == user_id[j].size()) {
                bool flag = true;

                for (int k = 0; k < banned_id[i].size(); ++k) {
                   if (banned_id[i][k] == '*') continue;
                   if (banned_id[i][k] != user_id[j][k]) {
                        flag = false;
                        break;
                   }
                }

                if (flag) {
                    v[i].push_back(j);
                }
            }

        }
    }

    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] ;
        }
        cout << endl;
    }*/

    dfs(0, "");
    
    return answer.size();
}