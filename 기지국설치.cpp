#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int start = 1;
    int dis = 2*w + 1;
    
    for (int i = 0; i < stations.size(); ++i) {
    	int left = stations[i] - w;
    	if (left > start) {
	    	int val = (left-start)/dis;
	    	int rest = (left-start)%dis;

	    	if (rest == 0) {
	    		answer += val;
	    	} else {
	    		answer += val + 1;
	    	}
    	}


    	if (i == stations.size()-1) {
    		start = stations[i] + w;
    	} else {
    		start = stations[i] + w + 1;
    	}
    	
    }

    if (start < n) {
    	int val = (n-start)/dis;
	    int rest = (n-start)%dis;

	    if (rest == 0) {
	    	answer += val;
	    } else {
	    	answer += val + 1;
	    }
    }

    return answer;
}