#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
	bool isSubsequence(string s, string t){
		auto i = s.begin();
		for (char c:t) i+= (*i == c);
		return i == s.end();
	}	
};


int main(){
	Solution s = Solution();
	bool r = s.isSubsequence("abc", "abarc");
	cout << r << endl;
	
	return 0;
}
