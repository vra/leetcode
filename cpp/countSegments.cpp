#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
    	int ret = 0;
    	bool in_word = false;
    	for (int i = 0; i < s.size(); ++i) {
    		if (s[i] != ' ' && !in_word) {
    			++ ret;
    			in_word = true;
    		}
    		if (s[i] == ' ') {
    			in_word = false;
    		}
    	}

    	return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.countSegments("Hello, my name is John") << endl;
	return 0;
}
