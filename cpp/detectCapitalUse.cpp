#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
		if (word.size() < 2) return true;
		if (word[0] >= 'a') {
			string copy = word;
			transform(word.begin(), word.end(), word.begin(), ::towlower);
			return word == copy;
		}
		else if (word[1]>= 'a') {
			return detectCapitalUse(word.substr(1));
		}
		else {
			string copy = word;
			transform(word.begin(), word.end(), word.begin(), ::toupper);
			return word == copy;
		}
    }
};

int main() {
	Solution s;
	cout << s.detectCapitalUse("HelloWorld") << endl;

	return 0;
}
