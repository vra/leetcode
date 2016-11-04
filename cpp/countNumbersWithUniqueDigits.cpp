#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
		if (n < 1) return 0;
		int result = 10;
		for (int i = 2; i <= n; ++i) {
			int curr_result = 9;
			int k = 9;
			while (k>=11-i)
			{
				curr_result *= k;
				--k;
			}
			result += curr_result;
		}

		return result;
    }
};

int main() {
	Solution s = Solution();
	int r = s.countNumbersWithUniqueDigits(1);
	int r1 = s.countNumbersWithUniqueDigits(2);
	int r2 = s.countNumbersWithUniqueDigits(3);
	int r3 = s.countNumbersWithUniqueDigits(4);

	return 0;
}
