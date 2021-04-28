#include <string>
#include <vector>
#include <map>

using namespace std;

int parent[10001];
int res[10001];

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    map<string, int> m;
    m["-"] = 0;

    for (int i = 0; i < enroll.size(); ++i) {
    	m[enroll[i]] = i+1;
    }

    parent[0] = -1;
    for (int i = 0; i < referral.size(); ++i) {
    	parent[i+1] = m[referral[i]];
    }

    for (int i = 0; i < seller.size(); ++i) {
    	int total = amount[i] * 100;

    	int idx = m[seller[i]];

    	while(idx > 0) {
    		if (total < 10) {
    			res[idx] += total;
    			break;
    		}
    		res[idx] += total - (total/10);
    		total /= 10;
    		idx = parent[idx];
    	} 
    	
    }

    for (int i = 1; i <= enroll.size(); ++i) {
    	answer.push_back(res[i]);
    }

    return answer;
}