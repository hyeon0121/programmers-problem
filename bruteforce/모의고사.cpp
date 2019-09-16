#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> student1 = {1, 2, 3, 4, 5};
	vector<int> student2 = {2, 1, 2, 3, 2, 4, 2, 5};
	vector<int> student3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

	int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;

	vector<int> answer;

	for (int i = 0; i < answers.size(); i++) {
		if (student1[i%5] == answers[i]) {
			cnt1++;
		} if (student2[i%8] == answers[i]) {
			cnt2++;
		} if (student3[i%10] == answers[i]) {
			cnt3++;
		}
	}

	int maxCount = max(cnt1, max(cnt2, cnt3));
	
	if (maxCount == cnt1) {
		answer.push_back(1);
	}

	if (maxCount == cnt2) {
		answer.push_back(2);
	}

	if (maxCount == cnt3) {
		answer.push_back(3);
	}
  
    return answer;
}