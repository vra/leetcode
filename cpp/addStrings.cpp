// Question link: https://leetcode.com/problems/add-strings/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution{
public:
	
	// Solution1: change each char to long long, overflow when str is too long.
	string addStrings(string num1, string num2) {
		if (num1.size() < num2.size()) swap(num1, num2);	
		int len1 = num1.size();
		int len2 = num2.size();
		long long result = 0;
		for (int i = 0; i < len1; ++i) {
			long long curr_sum = 0;
			if (len2 > i) {
				curr_sum = pow(10, i)*(num1[len1-i-1] + num2[len2-i-1] - 2 * '0');	
				result += curr_sum;
			}
			else {
				curr_sum = pow(10, i)*(num1[len1-i-1] - '0');	
				result += curr_sum;
			}
		}
	
		return to_string(result);
	}

	// Solution2: calculate the sum of the last two char, put the result into
	// string. 
	string addStrings2(string num1, string num2) {
		if (num1.size() < num2.size()) swap(num1, num2);	
		int len1 = num1.size();
		int len2 = num2.size();
		string result="";
		int up_bit = 0;
		int curr_sum = 0;
		for (int i = 0; i < len1; ++i) {
			if (len2 > i) {
				curr_sum = (num1[len1-i-1] + num2[len2-i-1] - 2 * '0' + up_bit);	
				up_bit = curr_sum / 10;
				curr_sum = curr_sum % 10;
				result = to_string(curr_sum) + result;
			}
			else {
				curr_sum = (num1[len1-i-1] - '0' + up_bit);	
				up_bit = curr_sum / 10;
				curr_sum = curr_sum % 10;
				result = to_string(curr_sum) + result;
			}
		}

		if (up_bit) result  = to_string(up_bit) + result;

		return result;
	}
};


int main() {
	Solution s = Solution();
	string r = s.addStrings2("9","99");
	cout << r << endl;

	return 0;
}
