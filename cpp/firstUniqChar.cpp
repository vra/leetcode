#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
		map<char, int> charMap;
		for (int i= 0; i < s.size(); ++i){
			if(charMap.count(s[i])){
				charMap[s[i]] = charMap[s[i]] + 1;
			}
			else
			{
				charMap[s[i]] = 1;
			}
		}
		for (int i = 0; i < s.size(); ++i){
			if (charMap[s[i]] == 1){
				return i;
			}
		}
		return -1;
    }
	int firstUniqChar2(string s) {
		int charArray[26] = {0};
		for (int i= 0; i < s.size(); ++i){
			if(charArray[s[i] - 'a']){
				charArray[s[i] - 'a'] += 1;
			}
			else
			{
				charArray[s[i]- 'a'] = 1;
			}
		}
		for (int i = 0; i < s.size(); ++i){
			if (charArray[s[i]-'a'] == 1){
				return i;
			}
		}
		return -1;
    }
}; 
int main()
{
	Solution s = Solution();
	int r = s.firstUniqChar2("loveleetcode");
	cout << r << endl;

	return 0;
}
