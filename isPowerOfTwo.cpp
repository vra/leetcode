#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
		if (n <=0)
		{
			return false;
		} 

		//power of 2 has only one of `1`, so we can use this trick.
		return !(n & (n - 1));
    }
};