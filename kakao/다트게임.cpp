#include <iostream>  
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int solution(string dartResult) {
    int cnt = 0;
    int arr[3];
    int idx = 0;
    
    for (int i = 0; i < dartResult.size(); i++) {
    	if (cnt == 0) {
    		arr[idx] = dartResult[i] - 48;

    	} else if (cnt == 1) {
    		if (dartResult[i] == '0') {
    			arr[idx] = 10;
                cnt--;

    		} else if (dartResult[i] == 'D') {
    			arr[idx] = pow(arr[idx], 2);

    		} else if (dartResult[i] == 'T') {
                arr[idx] = pow(arr[idx], 3);

    		}

    	} else {
    		if (dartResult[i] == '*') {
    			arr[idx] *= 2;

    			if (idx - 1 >= 0) {
    				arr[idx-1] *= 2;
    			}

    		} else if (dartResult[i] == '#') {
    			arr[idx] *= -1;

    		} else {
                i--;
            }

    		idx += 1;
    	}
    	
    	cnt++;
    	cnt %= 3;
    	
    }

    int sum = 0;

    for (int i = 0; i < 3; i++) {
        // cout << arr[i] << endl;
    	sum += arr[i];
    }

    return sum;
}

int main(void) {
	string s;
	cin >> s;
	
	cout << solution(s);

	return 0;
} 