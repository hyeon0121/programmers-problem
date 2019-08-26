#include <iostream>  
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    string str1 = "";
    string str2 = "";

    for (int i = 0; i < n; i++) {
    	int num = arr1[i] | arr2[i];    	

   		for (int i = 0; i < n; i++) {
	    	if (num % 2 == 1) {
	    		str1 += "#";
	    	} else {
	    		str1 += " ";
	    	}

	    	num /= 2;
    	}

    	for (int i = str1.size()-1; i >= 0; i--)
    	{
    		str2 += str1[i];
    	}

        cout << str2 << endl;
        
    	answer.push_back(str2);
    	str2 = "";
        str1 = "";
    }
    
    return answer;
}

int main() {
    int n, tmp;
    vector<int> arr1, arr2;
    vector<string> ans;
    
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr1.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr2.push_back(tmp);
    }

    ans = solution(n, arr1, arr2);
    

    for (int i = 0; i < n; i++) {
         cout << ans[i] << endl;
    }

    return 0;
}