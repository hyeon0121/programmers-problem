#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


bool cmp(pair<pair<string,int>,int> a, pair<pair<string,int>,int> b) {
	if (a.first.first == b.first.first) {
		if (a.first.second == b.first.second) {
			return a.second < b.second;
		} else {
			return a.first.second < b.first.second;
		}
	} else {
		return a.first.first < b.first.first;
	}
}
vector<string> solution(vector<string> files) {
    vector<string> answer(files.size());
    
    vector<pair<pair<string,int>,int>> v;

    for (int i = 0; i < files.size(); i++) {
    	string str;
    	for (int j = 0; j < files[i].size(); ++j) {
	        if (isdigit(files[i][j])) {
	            str = files[i].substr(0,j);

	            for (int k = 0; k < str.size(); ++k){
	            	str[k] = toupper(str[k]);
	            }
	            string num = "";
	            for (int k = j; k < files[i].size(); ++k){
	            	if (!isdigit(files[i][k])) break;
	            	else {
	            		num += files[i][k];
	            	}
	            }

	            pair<string,int> p = {str, stoi(num)};
	            v.push_back({p,i});
	            //cout << str << "," << stoi(num) << endl;
	            break;
	           
	        }
    	}
    	
    }

        //cout << v.size();
    sort(v.begin(), v.end(),cmp);


    /*for (int i = 0; i < v.size(); ++i) {
    	cout << v[i].first.second;
    }*/

    for (int i = 0; i < v.size(); ++i) {
    	answer[i] = files[v[i].second];
    }
    
    return answer;
}