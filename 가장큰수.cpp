#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const string &a, const string &b) {
	if (a == b) {
		return false;
	}

	string ab = a + b;
	string ba = b + a;

	if (ab > ba) {
		// cout << ab << ba << endl;
		return true;
	}

    return false;
}

string solution(vector<int> numbers) {
	string answer = "";
    vector<string> arr;
    int check = 0;

	for (int i = 0; i < numbers.size(); i++) {
		int n = numbers[i];
		arr.push_back(to_string(n));

		check += numbers[i];
	}

	sort(arr.begin(), arr.end(), cmp);

	if (check == 0) {
		return to_string(0);
	}

	for (int i = 0; i < arr.size(); i++) {
		//cout << arr[i] << endl;
		answer += arr[i];
	}

    return answer;
}