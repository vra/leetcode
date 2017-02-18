#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
    	int base7_num = 0;
    	int abs_num = abs(num);
 	int symbol = num == abs_num ? 1: -1;
    	int num_order = 0;
    	int left = 0;
    	while (abs_num / 7 ) {
    		left = abs_num % 7;
    		base7_num += int(pow(10, num_order)) * left;
    		++ num_order;
    		abs_num = abs_num / 7;
    	}
    	base7_num += int(pow(10, num_order)) * (abs_num % 7);
        
        return to_string(base7_num * symbol);
    }
};

int main() {
	Solution s;
	cout << s.convertToBase7(7) << endl;

	return 0;
}
