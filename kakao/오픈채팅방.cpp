#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <iterator>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string, string> nickname;
    vector<string> id;
    vector<bool> enter;

    for (int i = 0; i < record.size(); i++) {
        istringstream iss(record[i]);
        vector<string> cmds {istream_iterator<string>{iss},
            istream_iterator<string>{}};

        string cmd = cmds[0];
        if (!cmd.compare("Enter")) {
            id.push_back(cmds[1]);
            enter.push_back(true);
            nickname[cmds[1]] = cmds[2];
        } else if (!cmd.compare("Leave")) {
            id.push_back(cmds[1]);
            enter.push_back(false);
        } else if (!cmd.compare("Change")) {
            nickname[cmds[1]] = cmds[2];

        }

    }

    for (int i = 0; i < id.size(); i++) {
        string res = nickname[id[i]];
        if (enter[i]) {
            res += "님이 들어왔습니다.";
        } else {
            res += "님이 나갔습니다.";
        }

        answer.push_back(res);
    }

    return answer;
}