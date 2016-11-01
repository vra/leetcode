#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
		if (num < 10)
		{
			return num;
		}

		int sumOfNum = 0;
		while (num > 0)
		{
			int currDigit = num % 10;
			sumOfNum += currDigit;
			num = num / 10;
		}

		addDigits(sumOfNum);
    }
	int addDigitsConstant(int num)
	{
		//read here:https://en.wikipedia.org/wiki/Digital_root#Congruence_formula 
		//and https://leetcode.com/discuss/52122/accepted-time-space-line-solution-with-detail-explanations
		return 1 + (num - 1) % 9;
	}
};

int main()
{
	Solution s = Solution();
	//cout<< s.addDigits(38) << endl;
	cout<< s.addDigitsConstant(38) << endl;

	return 0;
}
