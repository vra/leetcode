#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
    bool wordPattern(string pattern, string str) {
		map<char, int> p2i;
		map<string, int> w2i;
		int i = 0;
		int n = pattern.size();
		istringstream iss(str);

		for (string word; iss >> word; ++i)
		{
			//i==n 说明str 比pattern的模块要多
			if (i == n || p2i[pattern[i] != w2i[word]])
			{
				return false;
			}

			p2i[pattern[i]] = w2i[word] = i + 1;
		}
	
		return i == n;
    }
};


int main()
{
	string pattern = "abba";
	string str = "dog cat cat dog";
	string str2 = "dog dog cat dog";

	Solution s = Solution();

	int r = s.wordPattern(pattern, str);
	int r2 = s.wordPattern(pattern, str2);

	return 0;
}