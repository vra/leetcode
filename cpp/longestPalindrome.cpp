#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
		map<char, int> charMap;
		int result = 0;
		bool has_single = false;
		for (int i = 0; i < s.size(); ++i) {
			++charMap[s[i]];
		}
        if (charMap.size() == 1) return charMap.begin()->second;
		for (auto iter = charMap.begin(); iter != charMap.end(); ++ iter) {
			if (iter->second % 2 == 0) {
				result += iter->second;
			}
			else
			{
				result += iter->second - 1;
				has_single = true;
			}
		}
		if (has_single) {
			result += 1;
		}
		return result;
    }
};

int main(){
	Solution s = Solution();
	int r = s.longestPalindrome("abc");

	return 0;
}
