//Idea from here: https://discuss.leetcode.com/topic/4485/concise-recursive-c-solution
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
    void addingpar(vector<string> &v, string str, int n, int m){
		cout << "n: " << n << ", m: " << m << ", str: " << str << endl;
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(m > 0){ addingpar(v, str+")", n, m-1); }
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
    }
};

int main() {
	Solution s = Solution();
	vector<string> r = s.generateParenthesis(3);

	return 0;
}
