#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

bool checkPrime(int n) {
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    
	//int half = n / 2;

	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0){
			return false;
		}
	}

	return true;
}

int solution(string numbers) {
   	int answer = 0;

	string temp = numbers;

    sort(temp.begin(), temp.end(), greater<int>());

    int size = stoi(numbers);

    vector<bool> prime(stoi(temp)+1);

    prime[0] = false;
    for (long long i = 1; i < prime.size(); i++) {
    	prime[i] = checkPrime(i);
    }

    string s = numbers;
    sort(s.begin(), s.end());
    set<int> primes;
    string sub;
    
	do {
		for (int i = 1; i <= s.size(); i++) {
	        sub = s.substr(0, i);
	        cout << sub << endl;
	        if (prime[stoi(sub)]) {
	            primes.insert(stoi(sub));
            
	        }
	    }
    } while (next_permutation(s.begin(), s.end()));

    answer = primes.size();
    return answer;
}