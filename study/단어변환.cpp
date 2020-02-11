#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dfs(string begin, string target, vector<string> words, int depth) {
	//cout << minV << endl;

	if (begin == target) {
		return depth;
	} 

	if (words.size() == 0) {
		return 987654321;
	}

	int minV = 987654321;


	vector<bool> nextWord(words.size(), false);

	for (int i = 0; i < words.size(); i++) {
		int cnt = 0;

		for (int j = 0; j < begin.length(); j++) {
			if (cnt > 1) break;
			if (words[i][j] != begin[j]) cnt++;
			
		}

		if (cnt == 1) {
			nextWord[i] = true;
			break;
		}
		
	}

	for (int i = 0; i < words.size(); i++) {
		if (nextWord[i]) {
			vector<string> tmp = words;
			tmp.erase(tmp.begin()+i);
			minV = min(minV, dfs(words[i], target, tmp, depth+1));
		}
	}

	return minV;
			

}

int solution(string begin, string target, vector<string> words) {
	if (find(words.begin(), words.end(), target) == words.end()) {
		return 0;
	}

	int answer = dfs(begin, target, words, 0);

	if (answer < 100) {
		return answer;
	}

    return 0;
}
