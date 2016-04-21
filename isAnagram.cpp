#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

		sort(s.begin(), s.end());
		sort(t.begin(), t.end());

		return s==t;
    }

	bool isAnagramAddMins(string s, string t)
	{
		int alp[26] = {};
		for (int i = 0; i < s.size(); ++i)
		{
			alp[s.at(i) - 'a'] ++;
		}

		for (int i = 0; i < t.size(); ++i)
		{
			alp[t.at(i) - 'a'] --;
		}

		for (int i = 0; i < 26; ++i)
		{
			if (alp[i] != 0)
			{
				return false;
			}
		}

		return true;
	}
};

