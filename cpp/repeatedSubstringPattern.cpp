#include <iostream>
#include <string>

using namespace std;


//Idea: search the second appearance of the first char. if reach the end,
// return false. if find the second pos(ie, i), check if the str can be 
// construct by substr str(0..i-1).if not, then go on searching the third
//appearance of the first char,util the end of str.
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
		bool hasDuplicatedChar = false;
		for (int i = 1; i < str.size(); ++i) {
			if (str[i] == str[0]) {
				if (canSubStrConstructStr(str, str.substr(0, i))) {
					return true;
				}
			}
		}
		return false;
    }

private:
	bool canSubStrConstructStr(string str, string subStr) {
		if (str.size() % subStr.size() != 0) return false;

		int times = str.size() / subStr.size();
		string constructedStr;
		for (int i = 0; i < times; ++i) {
			constructedStr += subStr;
		}

		return constructedStr == str;
	}
};


int main() {
	Solution s = Solution();
	cout << s.repeatedSubstringPattern("abcab") << endl;;
	cout << s.repeatedSubstringPattern("abcdaaa") << endl;;
	cout << s.repeatedSubstringPattern("abcde") << endl;;
	cout << s.repeatedSubstringPattern("abcda") << endl;;
	return 0;
}
