#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

map<string, char> mm;

string change(string s) {
	string tmp = "";
	for (int i = 0; i < s.size(); ++i) {
		if (s[i+1] == '#') {
			tmp += mm[s.substr(i,2)];
			i++;
		} else {
			tmp += s[i];
		}
	}

	return tmp;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";	
    int time = 0;

    mm["C#"] = 'Q';
    mm["D#"] = 'W';
    mm["F#"] = 'R';
    mm["G#"] = 'T';
    mm["A#"] = 'Y';

    string melody = change(m);


    for (int i = 0; i < musicinfos.size(); ++i) {
    	stringstream f(musicinfos[i]);
    	string s;
    	char token = ',';
    	vector<string> music;

    	while(getline(f,s,token)) {
    		music.push_back(s);
    	}

    	string start = music[0];
    	string end = music[1];

    	int h = stoi(end.substr(0,2)) - stoi(start.substr(0,2));
    	int m = stoi(end.substr(3,2)) - stoi(start.substr(3,2));

    	int play = h * 60 + m;

    	string info = change(music[3]);
    	string akbo = "";

    	if (play <= info.size()) {
    		akbo = info.substr(0,play);
    	} else {
	    	for (int j = 0; j < play / info.size(); ++j) {
	    		akbo += info;
	    	}

	    	akbo += info.substr(0,play % info.size());
    	}

    	if (akbo.find(melody) != string::npos) {
    		if (play > time) {
    			time = play;
    			answer = music[2];
    		}
    	} 	
    	
    }
    
    return answer;
}