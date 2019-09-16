#include <iostream>  
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> res;

    for (int i = 0; i < commands.size(); i++) {
    	vector<int> tmp;

    	for (int j = commands[i][0]; j <= commands[i][1]; j++) {
    		tmp.push_back(array[j-1]);
    	}

    	sort(tmp.begin(), tmp.end());

    	int idx = commands[i][2];
 		res.push_back(tmp[idx-1]);
    }
    return res;
}