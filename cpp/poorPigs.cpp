#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
		int n = 0;
		while (pow(minutesToTest / minutesToDie + 1, n) < buckets) ++ n;
		return n;
    }
};

int main() {
	Solution s;
	cout << s.poorPigs(1000, 15, 60) << endl;

	return 0;
}
