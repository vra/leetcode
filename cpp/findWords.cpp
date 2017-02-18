#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
    	unordered_map<char, int> lettes_map;
    	lettes_map['q'] = 1;
    	lettes_map['w'] = 1;
    	lettes_map['e'] = 1;
    	lettes_map['r'] = 1;
    	lettes_map['t'] = 1;
    	lettes_map['y'] = 1;
    	lettes_map['u'] = 1;
    	lettes_map['i'] = 1;
    	lettes_map['o'] = 1;
    	lettes_map['p'] = 1;
    	lettes_map['a'] = 2;
    	lettes_map['s'] = 2;
    	lettes_map['d'] = 2;
    	lettes_map['f'] = 2;
    	lettes_map['g'] = 2;
    	lettes_map['h'] = 2;
    	lettes_map['j'] = 2;
    	lettes_map['k'] = 2;
    	lettes_map['l'] = 2;
    	lettes_map['z'] = 3;
    	lettes_map['x'] = 3;
    	lettes_map['c'] = 3;
    	lettes_map['v'] = 3;
    	lettes_map['b'] = 3;
    	lettes_map['n'] = 3;
    	lettes_map['m'] = 3;

    	vector<string> result;
    	for (int i = 0; i < words.size(); ++i) {
    		int first_lettle_type = lettes_map[tolower(words[i][0])];
    		bool is_same = true;
    		for (int j = 1; j < words[i].size(); ++j) {
    			if (first_lettle_type != lettes_map[tolower(words[i][j])]) {
    				is_same = false;
    				break;
    			}
    		}

    		if (is_same) {
    			result.push_back(words[i]);
    		}
    	}

    	return result;
    }
};


int main(int argc, char const *argv[])
{
	vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
	Solution s;
	vector<string> r = s.findWords(words);
	for (int i = 0; i < r.size(); ++i) {
		cout << r[i] << endl;
	}
	return 0;
}
