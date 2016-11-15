#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		 long r = x;
        while (r*r > x)
            r = (r + x/r) / 2;
        return r;
	}
};
int main() {
	Solution s = Solution();
	cout << s.mySqrt(0) << endl;
	cout << s.mySqrt(1) << endl;
	cout << s.mySqrt(2) << endl;
	cout << s.mySqrt(3) << endl;
	cout << s.mySqrt(4) << endl;
	cout << s.mySqrt(5) << endl;

	return 0;
}
