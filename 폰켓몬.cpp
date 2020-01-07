#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums) {
	int cnt = 1;
	int size = nums.size() /2;

	sort(nums.begin(), nums.end());

	for (int i = 1; i < nums.size(); i++) {
		if (nums[i-1] != nums[i]){
			cnt++;
		}		
	}

    if (cnt > size) {
    	return size;
    } else if (cnt == 0) {
    	return 1;
    } else {
    	return cnt;
    }
	
}